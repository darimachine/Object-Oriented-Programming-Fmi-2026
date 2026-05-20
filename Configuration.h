#pragma once
#include<vector>
#include<memory>
#include<optional>
#include"Component.h"

class Configuration
{
private:
	vector<unique_ptr<Component>> components;

public:
	Configuration() = default;

	static optional<unique_ptr<Component>> createComponent(const string& type);
	void insert(const unique_ptr<Component>& component);
	double price()const;
	size_t size()const;

	const unique_ptr<Component>& operator[](size_t index)const;
	friend ostream& operator<<(ostream& os, const Configuration& c);
};

