#include "PackageValidator.h"

bool PackageValidator::checkPackages(const std::vector<std::unique_ptr<Package>>& packages, const std::string& number)
{
	auto it = std::find_if(packages.begin(), packages.end(), [&number](const std::unique_ptr<Package>& package)
		{
			return package->getTrackingNumber() == number;
		});

	return it != packages.end();
}