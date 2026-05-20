#include "Configuration.h"
#include"CPU.h"
#include"Memory.h"

optional <unique_ptr<Component>> Configuration::createComponent(const string& type)
{
	if (type == "CPU")
	{
		return make_unique<CPU>(type);
	}
	else if (type == "memory")
	{
		return make_unique<Memory>(type);
	}

	return nullptr;
}

void Configuration::insert(const unique_ptr<Component>& component)
{
	components.push_back(component->clone());
}

const unique_ptr<Component>& Configuration::operator[](size_t index)const
{
	if (index >= components.size())
	{
		throw out_of_range("Index is out of range.");
	}

	return components[index];
}

double Configuration::price()const
{
	double price = 0;

	for (const auto& component : components)
	{
		price += component->price();
	}
	return price;
}

size_t Configuration::size()const
{
	return components.size();
}

ostream& operator<<(ostream& os, const Configuration& c)
{
	for (const auto& component : c.components)
	{
		component->output(os);
	}

	return os << "Price: " << c.price() << '\n';
}