#include "MarketPlace.h"

//partial_orderin because we compare double numbers, it can be made with strong_ordering as well
partial_ordering MarketPlace::operator<=>(const MarketPlace& other) const
{
	double sumOfCurrentMerchant = getProfit();

	double sumOfOtherMerchant = other.getProfit();

	if (abs(sumOfCurrentMerchant - sumOfOtherMerchant) < 0.001) {
		double myRatio = (double)size / capacity;
		double otherRatio = (double)other.size / other.capacity;
		return myRatio <=> otherRatio;
	}
	return sumOfCurrentMerchant <=> sumOfOtherMerchant;

}
void MarketPlace::free()
{
	delete[] description;
	for (int i = 0; i < capacity; i++)
	{
		if (merchants[i]) {
			delete merchants[i];
		}
		merchants[i] = nullptr;
	}
	delete[] merchants;
	merchants = nullptr;
}

void MarketPlace::copyFrom(const MarketPlace& other)
{
	size = other.size;
	capacity = other.capacity;
	slotRent = other.slotRent;
	
	int len = strlen(other.description);
	description = new char[len + 1];
	strcpy(description, other.description);

	merchants = new Merchant * [capacity] {nullptr};
	for (int i = 0; i < capacity; i++)
	{
		if (other.merchants[i]) {
			merchants[i] = new Merchant(*other.merchants[i]);
		}
	}

}

void MarketPlace::moveFrom(MarketPlace&& other) noexcept
{
	capacity = other.capacity;
	other.capacity = 0;

	size = other.size;
	other.size = 0;

	slotRent = other.slotRent;
	other.slotRent = 0;

	description = other.description;
	other.description = nullptr;

	merchants = other.merchants;
	other.merchants = nullptr;
}

MarketPlace::MarketPlace(const char* description, unsigned int capacity, double slotRent) : capacity(capacity), slotRent(slotRent)
{
	int len = strlen(description);
	this->description = new char[len + 1];
	strcpy(this->description, description);

	merchants = new Merchant * [capacity] {nullptr};


}

MarketPlace::MarketPlace(const MarketPlace& other)
{
	copyFrom(other);
}

MarketPlace& MarketPlace::operator=(const MarketPlace& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MarketPlace::MarketPlace(MarketPlace&& other) noexcept
{
	moveFrom(std::move(other));
}

MarketPlace& MarketPlace::operator=(MarketPlace&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MarketPlace::~MarketPlace()
{
	free();
}

MarketPlace& MarketPlace::operator+=(const Merchant& m)
{
	if (size == capacity) {
		delete merchants[size - 1];
		merchants[size - 1] = new Merchant(m);
		return *this;
	}

	for (int i = 0; i < capacity; i++)
	{
		if (merchants[i] == nullptr) {
			merchants[i] = new Merchant(m);
			break;
		}
	}

	size++;
	return *this;
}

MarketPlace& MarketPlace::operator-=(double minRevenue)
{
	for (int i = 0; i < capacity; i++)
	{
		if (merchants[i] && merchants[i]->getIncome() < minRevenue) {
			delete merchants[i];
			merchants[i] = nullptr;
			size--;
		}
	}
	
	return *this;
}

MarketPlace& MarketPlace::operator()(int days)
{
	for (int i = 0; i < capacity; i++)
	{
		if (merchants[i]) {
			for (int j = 0; j < days; j++)
			{
				++(*merchants[i]);
			}
		}
	}
	return *this;
}
MarketPlace::operator bool() const {
	return size > (capacity / 2.00);
}
void MarketPlace::addAt(int pos, const Merchant& m)
{
	if (merchants[pos]) {
		delete merchants[pos];
	}
	else {
		size++;
	}
	merchants[pos] = new Merchant(m);

}
bool MarketPlace::isFreeSlot(int pos) const
{
	return merchants[pos] == nullptr;
}
unsigned int MarketPlace::takenSlots() const
{
	return size;
}
double MarketPlace::getProfit() const
{
	double sum = 0;

	for (int i = 0; i < capacity; i++)
	{
		if (merchants[i]) {
			sum += merchants[i]->getIncome();
		}
	}

	sum -= (slotRent * size);

	return sum;
}
double MarketPlace::averageProfit() const
{
	if (size == 0) {
		return 0;
	}

	return getProfit() / size;
}



ostream& operator<<(ostream& os, const MarketPlace& m)
{
	for (int i = 0; i < m.capacity; i++) {
		if (m.merchants[i] == nullptr) {
			os << "*";
		}
		else {
			os << m.merchants[i]->getId() << " ";
		}
	}
	os << m.description;
	os << m.slotRent;
	return os;
}
