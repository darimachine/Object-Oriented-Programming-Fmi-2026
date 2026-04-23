#include "VehicleList.h"

VehicleList::VehicleList(size_t capacity)
    : data(nullptr), currentSize(0), currentCapacity(capacity)
{
    if (capacity == 0)
    {
        throw std::invalid_argument("Capacity must be greater than 0.");
    }

    data = new Vehicle * [currentCapacity];
    for (size_t i = 0; i < currentCapacity; ++i)
    {
        data[i] = nullptr;

    }
}

VehicleList::VehicleList(const VehicleList& other)
{
    copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

VehicleList::~VehicleList()
{
    free();
}

void VehicleList::copyFrom(const VehicleList& other)
{
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;
    data = new Vehicle * [currentCapacity];

    for (size_t i = 0; i < currentCapacity; ++i)
    {
        if (other.data[i] == nullptr)
        {
            data[i] = nullptr;
        }
        else
        {
            data[i] = new Vehicle(*other.data[i]);
        }
    }
}

void VehicleList::free()
{
    for (size_t i = 0; i < currentCapacity; ++i)
    {
        delete data[i];
    }

    delete[] data;
    data = nullptr;
    currentSize = 0;
    currentCapacity = 0;
}

void VehicleList::resize()
{
    size_t newCapacity = currentCapacity * 2;
    Vehicle** newData = new Vehicle * [newCapacity];

    for (size_t i = 0; i < newCapacity; ++i)
    {
        newData[i] = nullptr;
    }

    for (size_t i = 0; i < currentCapacity; ++i)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    currentCapacity = newCapacity;
}

int VehicleList::findIndexByReg(const Registration& reg) const
{
    for (size_t i = 0; i < currentCapacity; ++i)
    {
        if (data[i] != nullptr && data[i]->getRegistration() == reg)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

VehicleList& VehicleList::operator+=(const Vehicle& vehicle)
{
    if (findIndexByReg(vehicle.getRegistration()) != -1)
    {
        return *this; 
    }

    size_t freeSlot = currentCapacity;
    for (size_t i = 0; i < currentCapacity; ++i)
    {
        if (data[i] == nullptr)
        {
            freeSlot = i;
            break;
        }
    }

    if (freeSlot == currentCapacity)
    {
        resize();
        for (size_t i = 0; i < currentCapacity; ++i)
        {
            if (data[i] == nullptr)
            {
                freeSlot = i;
                break;
            }
        }
    }

    data[freeSlot] = new Vehicle(vehicle);
    ++currentSize;

    return *this;
}

VehicleList& VehicleList::operator-=(const Registration& reg)
{
    int index = findIndexByReg(reg);
    if (index != -1)
    {
        delete data[index];
        data[index] = nullptr;
        --currentSize;
    }

    return *this;
}

bool VehicleList::operator==(const VehicleList& other) const
{
    if (currentSize != other.currentSize)
    {
        return false;
    }

    for (size_t i = 0; i < currentCapacity; ++i)
    {
        const Vehicle* left = (i < currentCapacity) ? data[i] : nullptr;
        const Vehicle* right = (i < other.currentCapacity) ? other.data[i] : nullptr;
        if ((left == nullptr) != (right == nullptr))
        {
            return false;
        }

        if (left != nullptr && right != nullptr)
        {
            if (left->getRegistration() != right->getRegistration())
            {
                return false;
            }
        }
    }

    return true;
}

bool VehicleList::operator!=(const VehicleList& other) const
{
    return !(*this == other);
}

bool VehicleList::operator<(const VehicleList& other) const
{
    if (currentSize != other.currentSize)
    {
        return currentSize < other.currentSize;
    }

    size_t maxCapacity = (currentCapacity > other.currentCapacity)
        ? currentCapacity
        : other.currentCapacity;

    for (size_t i = 0; i < maxCapacity; ++i)
    {
        const Vehicle* left = (i < currentCapacity) ? data[i] : nullptr;
        const Vehicle* right = (i < other.currentCapacity) ? other.data[i] : nullptr;

        if (left == nullptr && right == nullptr)
        {
            continue;
        }

        if (left == nullptr && right != nullptr)
        {
            return true;
        }

        if (left != nullptr && right == nullptr)
        {
            return false;
        }

        if (left->getRegistration() != right->getRegistration())
        {
            return left->getRegistration() < right->getRegistration();
        }
    }

    return false;
}

bool VehicleList::operator>(const VehicleList& other) const
{
    return other < *this;
}

size_t VehicleList::operator()(const char* townCode) const
{
    if (!townCode)
    {
        return 0;
    }

    size_t count = 0;
    for (size_t i = 0; i < currentCapacity; ++i)
    {
        if (data[i] != nullptr && data[i]->getRegistration().getTownCode() == townCode)
        {
            ++count;
        }
    }

    return count;
}

VehicleList::operator bool() const
{
    return currentSize > 0;
}

Vehicle* VehicleList::operator[](size_t index)
{
    if (index >= currentCapacity)
    {
        throw std::out_of_range("Index out of range.");
    }

    return data[index];
}

const Vehicle* VehicleList::operator[](size_t index) const
{
    if (index >= currentCapacity)
    {
        throw std::out_of_range("Index out of range.");
    }

    return data[index];
}

bool VehicleList::isFreeSlot(size_t pos) const
{
    if (pos >= currentCapacity)
    {
        throw std::out_of_range("Position out of range.");
    }

    return data[pos] == nullptr;
}

bool VehicleList::isEmpty() const
{
    return currentSize == 0;
}

size_t VehicleList::capacity() const
{
    return currentCapacity;
}

size_t VehicleList::size() const
{
    return currentSize;
}

Vehicle* VehicleList::find(const Registration& reg)
{
    int index = findIndexByReg(reg);
    if (index == -1)
    {
        return nullptr;
    }

    return data[index];
}

const Vehicle* VehicleList::find(const Registration& reg) const
{
    int index = findIndexByReg(reg);
    if (index == -1)
    {
        return nullptr;
    }

    return data[index];
}

std::ostream& operator<<(std::ostream& os, const VehicleList& list)
{
    for (size_t i = 0; i < list.currentCapacity; ++i)
    {
        if (list.data[i] == nullptr)
        {
            os << "[*]";
        }
        else
        {
            os << "[" << list.data[i]->getRegistration() << "]";
        }

        if (i + 1 < list.currentCapacity)
        {
            os << " ";
        }
    }

    return os;
}
