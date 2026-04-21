#include "Vehicle.h"

auto operator<<(std::ostream& os, const Vehicle& vehicle) -> std::ostream&
{
    os << "Vehicle: " << vehicle.m_registration << ", " << vehicle.m_description << ", " << vehicle.m_yearOfProduction << ", " << vehicle.m_engineHorsePower;
    return os;
}

void Vehicle::_free()
{
    if (m_description != nullptr)
        delete[] m_description;
    m_description = nullptr;
}

void Vehicle::_copy(const Vehicle& from)
{
    auto descriptionLength = strnlen_s(from.m_description, ULONG_MAX);
    m_description = new char[descriptionLength + 1];
    strcpy_s(m_description, descriptionLength + 1, from.m_description);
}

void Vehicle::_move(Vehicle&& from)
{
    m_description = from.m_description;

    from.m_registration = Registration{ "invalid" };
    from.m_description = nullptr;
    from.m_yearOfProduction = 0;
    from.m_engineHorsePower = 0;
}

Vehicle::Vehicle(const Registration& registration, const char* description, unsigned int yearOfProduction, unsigned int engineHorsePower) :
    m_registration(registration), m_yearOfProduction(yearOfProduction), m_engineHorsePower(engineHorsePower)
{
    auto descriptionLenght = strnlen_s(description, ULONG_MAX);
    m_description = new char[(descriptionLenght) ? (descriptionLenght + 1) : 1];
    (descriptionLenght) ? strcpy_s(m_description, descriptionLenght + 1, description) : strcpy_s(m_description, 1, "");
}

Vehicle::~Vehicle()
{
    _free();
}

Vehicle::Vehicle(const Vehicle& other) :
    m_registration(other.m_registration), m_yearOfProduction(other.m_yearOfProduction), m_engineHorsePower(other.m_engineHorsePower)
{
    _copy(other);
}

Vehicle::Vehicle(Vehicle&& other) noexcept :
    m_registration(std::move(other.m_registration)), m_yearOfProduction(std::move(other.m_yearOfProduction)), m_engineHorsePower(std::move(other.m_engineHorsePower))
{
    _move(std::move(other));
}

auto Vehicle::operator=(const Vehicle& other) -> Vehicle&
{
    _free();

    m_registration = other.m_registration;
    m_yearOfProduction = other.m_yearOfProduction;
    m_engineHorsePower = other.m_engineHorsePower;
    _copy(other);

    return *this;
}

auto Vehicle::operator=(Vehicle&& other) noexcept -> Vehicle&
{
    _free();

    m_registration = std::move(other.m_registration);
    m_yearOfProduction = std::move(other.m_yearOfProduction);
    m_engineHorsePower = std::move(other.m_engineHorsePower);
    _copy(std::move(other));

    return *this;
}

auto Vehicle::operator==(const Vehicle& other) const -> bool
{
    return ((*this) <=> other) == std::partial_ordering::equivalent;
}

auto Vehicle::operator<=>(const Vehicle& other) const -> std::partial_ordering
{
    if (this->m_registration == other.m_registration)
        return std::partial_ordering::equivalent;

    if (this->m_yearOfProduction < other.m_yearOfProduction)
        return std::partial_ordering::less;
    else if (this->m_yearOfProduction > other.m_yearOfProduction)
        return std::partial_ordering::greater;

    if (this->m_engineHorsePower < other.m_engineHorsePower)
        return std::partial_ordering::less;
    else if (this->m_engineHorsePower > other.m_engineHorsePower)
        return std::partial_ordering::greater;
    else
        return std::partial_ordering::unordered;
}
