#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Component.h"
#include "ComponentFactory.hpp"

class Configuration
{
private:
	std::vector<std::unique_ptr<Component>> components;

public: 
	void insert(const std::unique_ptr<Component>& component);
	double price() const;
	size_t size() const;

	const Component& operator[](int index) const;

	friend std::ostream& operator<<(std::ostream& os, const Configuration& config);
};

