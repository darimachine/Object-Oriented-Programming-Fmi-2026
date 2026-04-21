#include "VehicleList.h"

auto operator<<(std::ostream& os, const VehicleList& vehicleList) -> std::ostream&
{
	for (auto i = size_t{ 0 }; i < vehicleList.m_capacity; ++i)
	{
		if (vehicleList.m_vehicles[i] != nullptr)
			os << *(vehicleList.m_vehicles[i]) << "\n\r";
		else
			os << "Empty slot: *" << "\n\r";
	}

	return os;
}

auto VehicleList::_resize(size_t capacity) -> Vehicle**
{
	if (capacity == m_capacity)
		return m_vehicles;

	auto** newVehicles = new Vehicle * [capacity] {};
	for (auto i = size_t{ 0 }; i < m_capacity; ++i)
	{
		newVehicles[i] = m_vehicles[i];
	}
	m_capacity = capacity;
	delete[] m_vehicles;
	m_vehicles = newVehicles;

	return m_vehicles;
}

auto VehicleList::_findVehicleByRegistration(const Registration& registration) const -> size_t
{
	for (auto i = size_t{ 0 }; i < m_capacity; ++i)
	{
		if (m_vehicles[i] != nullptr)
			if ((*(m_vehicles[i])).m_registration == registration)
				return i;
	}
	return m_capacity;
}

void VehicleList::_free()
{
	if (m_vehicles == nullptr)
		return;

	for (auto i = size_t{ 0 }; i < m_capacity; ++i)
	{
		if (m_vehicles[i] != nullptr)
			delete m_vehicles[i];
	}
	delete[] m_vehicles;
	m_vehicles = nullptr;
}

void VehicleList::_copy(const VehicleList& from)
{
	m_capacity = from.m_capacity;
	m_count = from.m_count;
	if (!m_capacity)
		return;

	m_vehicles = new Vehicle * [m_capacity] {};
	for (auto i = size_t{ 0 }; i < m_capacity; ++i)
	{
		if (from.m_vehicles[i] == nullptr)
		{
			m_vehicles[i] = nullptr;
			continue;
		}

		m_vehicles[i] = new Vehicle{ *from.m_vehicles[i] };
	}
}

void VehicleList::_move(VehicleList&& from)
{
	m_capacity = from.m_capacity;
	m_count = from.m_count;
	m_vehicles = from.m_vehicles;

	from.m_capacity = 0;
	from.m_count = 0;
	from.m_vehicles = nullptr;
}

VehicleList::VehicleList(size_t capacity)
	: m_capacity(capacity), m_count(0)
{
	m_vehicles = nullptr;
	if (m_capacity > 0)
		m_vehicles = new Vehicle * [m_capacity] {};
}

VehicleList::~VehicleList()
{
	_free();
}

VehicleList::VehicleList(const VehicleList& other)
{
	_copy(other);
}

VehicleList::VehicleList(VehicleList&& other) noexcept
{
	_move(std::move(other));
}

auto VehicleList::operator=(const VehicleList& other) -> VehicleList&
{
	_free();
	_copy(other);

	return *this;
}

auto VehicleList::operator=(VehicleList&& other) noexcept -> VehicleList&
{
	_free();
	_move(std::move(other));

	return *this;
}

auto VehicleList::operator+=(const Vehicle& vehicle) -> VehicleList&
{
	auto index = _findVehicleByRegistration(vehicle.m_registration);
	if (index != m_capacity)
		return *this;

	if (m_capacity == m_count)
	{
		if (m_capacity * 2 < m_capacity)
			return *this;

		_resize(std::max(1ull, m_capacity * 2));
	}

	for (auto i = size_t{ 0 }; i < m_capacity; ++i)
	{
		if (m_vehicles[i] == nullptr)
		{
			m_vehicles[i] = new Vehicle{ vehicle };
			++m_count;
			break;
		}
	}

	return *this;
}

auto VehicleList::operator-=(const Registration& registration) -> VehicleList&
{
	auto index = _findVehicleByRegistration(registration);
	if (index == m_capacity)
		return *this;

	delete m_vehicles[index];
	m_vehicles[index] = nullptr;
	--m_count;

	return *this;
}

auto VehicleList::operator()(const char* areaCode) -> size_t
{
	auto areaCodeLenght = strnlen_s(areaCode, 2);
	if (areaCodeLenght < 1 || areaCodeLenght > 2)
		return 0;
	auto result = size_t{ 0 };
	for (auto i = size_t{ 0 }; i < m_capacity; ++i)
	{
		if (m_vehicles[i] != nullptr)
			if (!strcmp(m_vehicles[i]->m_registration.m_areaCode, areaCode))
				++result;
	}
	return result;
}

auto VehicleList::operator[](size_t index) const -> Vehicle*
{
	if (index >= m_capacity) return nullptr;
	return m_vehicles[index];
}

auto VehicleList::operator[](size_t index) -> Vehicle*
{
	if (index >= m_capacity) return nullptr;
	return m_vehicles[index];
}

auto VehicleList::operator==(const VehicleList& other) const -> bool
{
	return ((*this) <=> other) == std::partial_ordering::equivalent;
}

VehicleList::operator bool() const
{
	return m_count > 0;
}

auto VehicleList::isFreeSlot(size_t position) -> bool
{
	if (position >= m_capacity) return false;
	return m_vehicles[position] == nullptr;
}

auto VehicleList::isEmpty() -> bool
{
	return m_count == 0;
}

auto VehicleList::capacity() -> size_t
{
	return m_capacity;
}

auto VehicleList::size() -> size_t
{
	return m_count;
}

auto VehicleList::find(const Registration& registration) -> Vehicle*
{
	auto index = _findVehicleByRegistration(registration);
	if (index == m_capacity)
		return nullptr;

	return m_vehicles[index];
}

auto VehicleList::operator<=>(const VehicleList& other) const -> std::partial_ordering
{
	if (this->m_count < other.m_count)
		return std::partial_ordering::less;
	else if (this->m_count > other.m_count)
		return std::partial_ordering::greater;

	if (!m_count)
		return std::partial_ordering::equivalent;

	Registration* r1 = nullptr, * r2 = nullptr;
	for (auto i = size_t{ 0 }; i < m_count; ++i)
	{
		if (m_vehicles[i] != nullptr)
		{
			r1 = &m_vehicles[i]->m_registration;
			break;
		}
	}
	for (auto i = size_t{ 0 }; i < other.m_count; ++i)
	{
		if (other.m_vehicles[i] != nullptr)
		{
			r2 = &other.m_vehicles[i]->m_registration;
			break;
		}
	}

	if (r1 == nullptr || r2 == nullptr)
		return std::partial_ordering::unordered;
	return (*r1) <=> (*r2);
}
