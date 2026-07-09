#pragma once
#include"Package.h"
#include<vector>
#include<memory>
#include<algorithm>

class PackageValidator
{
public:
	PackageValidator() = delete;
	static bool checkPackages(const std::vector<std::unique_ptr<Package>>& packages, const std::string& number);
};