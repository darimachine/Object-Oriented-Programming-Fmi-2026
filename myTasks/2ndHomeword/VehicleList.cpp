#include  <iostream>
#include  <print>
#include "VehicleList.h"

VehicleList::VehicleList(size_t inpCap): capacity(inpCap)
{
    vechileLists = new Vehicle*[capacity];
    for (int i =0; i < capacity; i++)
    {
        vechileLists[i] = nullptr;
    }
    vechileCount = 0;
}

void VehicleList::resize(size_t NewCap)
{
    capacity = NewCap;
    Vehicle ** temp = new Vehicle*[capacity];

    for (int i =0; i < vechileCount; i++)
    {
        temp[i] = vechileLists[i];
    }
    delete [] vechileLists;
    vechileLists = temp;
}

VehicleList &VehicleList::operator+=(const Vehicle& obj)
{
    const Registration& joiningVReg = obj.getRegistration();
    for (int i =0; i < vechileCount; i++)
    {
        const Registration& currReg = vechileLists[i]->getRegistration();

        if (vechileLists[i] != nullptr)
        {
            if (currReg == joiningVReg)
            {
                return *this;
            }
        }
    }

    if (vechileCount == capacity)
    {
        resize(capacity * 2);
    }

    for (int i =0; i < vechileCount; i++)
    {
        if (vechileLists[i] == nullptr)
        {
            vechileLists[i] = new Vehicle(obj);
            vechileCount++;
            break;
        }
    }
    return *this;
}

VehicleList &VehicleList::operator-=(const Vehicle& obj)
{
    const Registration& removingRegNum = obj.getRegistration();
    for (int i =0; i < capacity; i++)
    {
        if (vechileLists[i] != nullptr)
        {
            const Registration& currReg = vechileLists[i]->getRegistration();
            if (removingRegNum == currReg)
            {
                delete vechileLists[i];
                vechileLists[i] = nullptr;
                vechileCount--;
                break;
            }
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& currList)
{
    for (int i =0; i< currList.capacity; i++)
    {
        if (currList.vechileLists[i] != nullptr)
        {
            os<<*(currList.vechileLists[i])<<'\n';
        }
        else
        {
            os<<'*'<<'\n';
        }
    }
    return os;
}
bool operator==(const VehicleList& rhs, const VehicleList& lhs)
{
    return rhs.vechileCount == lhs.vechileCount;
}

std::strong_ordering VehicleList::operator<=>(const VehicleList &other)
{
    if (auto cmp = vechileCount <=> other.vechileCount; cmp!=0)
    {
        return  cmp;
    }

    int minCapacity = capacity < other.capacity ? capacity : other.capacity;
    for (int i =0; i < minCapacity; i++)
    {
        if (vechileLists[i] != nullptr && other.vechileLists[i] != nullptr)
        {
            const Registration& rhsReg = vechileLists[i]->getRegistration();
            const Registration& lhsReg = other.vechileLists[i]->getRegistration();
            return  rhsReg <=> lhsReg;
        }
    }
}

int VehicleList::operator()(const char *inpPlace) const
{
    if (!inpPlace)
    {
        return  -2;
    }

    size_t lenInpPlace = strlen(inpPlace);
    if (lenInpPlace >2)
    {
        return  -2;
    }

    int countVehicles =0;
    const size_t firstTwoSymbLen = lenInpPlace;
    for (int i =0; i < capacity; i++)
    {
        if (vechileLists[i] != nullptr)
        {
            const char* currReg = vechileLists[i]->getRegistration().getRegNumb();
             char *fistTwoSymb = new char[firstTwoSymbLen + 1];

             for (int j =0; j <firstTwoSymbLen; j++)
             {
                 fistTwoSymb[j] = currReg[j];
             }

            if (lenInpPlace == 1)
            {
                if (fistTwoSymb[0] == inpPlace[0])
                {
                    countVehicles++;
                }
            }
            else
            {
                if (fistTwoSymb[0] == inpPlace[0] && fistTwoSymb[1] == inpPlace[1])
                {
                    countVehicles++;
                }
            }
            delete [] fistTwoSymb;
        }
    }
    return  countVehicles;
}

VehicleList::operator bool() const
{
    if (vechileCount >0)
    {
        return  true;
    }
    return  false;
}

bool VehicleList::isFreeSlot(size_t pos) const
{
    if (pos > capacity)
    {
        return false;
    }

    if (vechileLists[pos] == nullptr)
    {
        return  true;
    }
    return false;
}

bool VehicleList::isEmpty() const
{
    if (vechileLists)
    {
        return false;
    }
    return true;
}

int VehicleList::getCapacity() const
{
    return  capacity;
}

int VehicleList::getSize() const
{
    return vechileCount;
}

Vehicle *VehicleList::find(const Registration &searchingRegNum) const
{
    for (int i =0; i < capacity; i++)
    {
        if (vechileLists[i] != nullptr)
        {
            const Registration& currRegNum = vechileLists[i]->getRegistration();
            if (currRegNum == searchingRegNum)
            {
                return vechileLists[i];
            }
        }
    }

    return nullptr;
}

int main()
{


    return 0;
}