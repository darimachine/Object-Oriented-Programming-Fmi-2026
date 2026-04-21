#include "VehicleList.h"



int VehicleList::getOpenSlot()
{
	for (size_t i = 0; i < size(); i++)
	{
		if (list[i])// == nullptr)
		{
			return i;
		}
	}
	return -1;
}

void VehicleList::doubleSize()
{
	Vehicle** temp = new Vehicle * [size() * 2] {nullptr};
	for (size_t i = 0; i < size(); i++)
	{
		temp[i] = list[i];
	}
	delete[] list;
	list = temp;
	_size *= 2;
}

int VehicleList::getVehicleSlot(Vehicle& v)
{

	for (size_t i = 0; i < size(); i++)
	{
		if (!isFreeSlot(i))
		{
			if (list[i]->getRegistration() == v.getRegistration())
			{
				return i;
			}
		}
	}

	return -1;
}

int VehicleList::getFistOpenSlot()
{
	for (size_t i = 0; i < size(); i++)
	{
		if (this->isFreeSlot(i))
		{
			return i;
		}
	}
	return -1;
}


bool VehicleList::isFreeSlot(int pos)
{
	return list[pos] == nullptr;
}

VehicleList::VehicleList(int size1)
{
	if (size1<=0)
	{
		this->_size = 10;
	}
	else
	{
		_size = size1;
	}
	list = new Vehicle*[_size]{nullptr};
	_capacity = 0;
}

VehicleList::~VehicleList()
{
	
	delete[] list;
}

Vehicle* VehicleList::find(Registration& reg)
{
	for (size_t i = 0; i < size(); i++)
	{
		if (!isFreeSlot(i))
		{
			if (list[i]->getRegistration()==reg)
			{
				return list[i];
			}
		}
	}

	return nullptr;
}

VehicleList& VehicleList::operator+=( Vehicle& v)
{
	if (find(v.getRegistration()))
	{
		return *this;
	}
	if (capacity() >= size())
	{
		doubleSize();
	}
	int openSlot = getOpenSlot();
	if (openSlot == -1)
	{
		return *this; 
	}
	list[openSlot] = &v;
	_capacity++;
	return *this;
}

VehicleList& VehicleList::operator-=(Registration& reg)
{
	if (!find(reg))
	{
		return *this;
	}
	int vSlot = getVehicleSlot(*find(reg));
	
	list[vSlot] = nullptr;
	_capacity--;
	
	return *this;
}

bool VehicleList::operator==(VehicleList& other)
{
	if (this->capacity()==other.capacity())
	{
		return true;
	}
	Registration thisVehReg = (this->list[this->getFistOpenSlot()]->getRegistration());
	Registration otherVehReg = other[this->getFistOpenSlot()].getRegistration();
	if (thisVehReg==otherVehReg) {
		return true;
	}
	return false;
}

std::strong_ordering VehicleList::operator<=>(VehicleList& other)
{
	if (*this==other)
	{
		return std::strong_ordering::equal;
	}
	if (this->capacity() > other.capacity())
	{
		return std::strong_ordering::greater;
	}
	if (this->capacity() < other.capacity())
	{
		return std::strong_ordering::less;
	}

	Registration thisVehReg = (this->list[this->getFistOpenSlot()]->getRegistration());
	Registration otherVehReg = other[this->getFistOpenSlot()].getRegistration();
	if (thisVehReg > otherVehReg) {
		return std::strong_ordering::greater;

	}
	if (thisVehReg < otherVehReg) {
		return std::strong_ordering::less;

	}

	return std::strong_ordering::equal;
}

int VehicleList::operator()(const char* code)
{
	int count = 0;
	for (size_t i = 0; i < size(); i++)
	{
		if (!isFreeSlot(i))
		{

			if (strlen(code) == 1) {
				if (list[i]->getRegistration().getNumber()[0] == code[0])
				{
					count++;
				}
			}
			else
			if (strlen(code) == 2) {
				if (list[i]->getRegistration().getNumber()[0] == code[0]&&
					list[i]->getRegistration().getNumber()[1] == code[1])
				{
					count++;
				}
			}

		}
	}
	return count;
}

VehicleList::operator bool()
{
	return _capacity != 0;
}

Vehicle& VehicleList::operator[](int index)
{
	return *list[index];
}

bool VehicleList::isEmpty()
{
	return _capacity == 0;
}

int VehicleList::capacity()
{
	return _capacity;
}

int VehicleList::size()
{
	return _size;
}

std::ostream& operator<<(std::ostream& os, VehicleList& v)
{

	os << "Size: " << v.size() << " \n"
		<< "Filled slots: " << v.capacity() << " \n"
		<< "Vehicles in the list: \n";
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v.isFreeSlot(i))
		{
			os << "[ * ] ";
			continue;
		}
		else
		{
			os <<"[ " << v.list[i]<<" ] ";
		}
	}
	os << "\n";

	return os;
}
