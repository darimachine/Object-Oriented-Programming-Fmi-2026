#pragma once
#include <string>
#include <memory>

enum class FeatureKind 
{
	Volcano,
	Forest,
	Lake,
	Bog,
	Mountain,
	Desert 
};

std::string featureKindToString(FeatureKind kind);
FeatureKind featureKindFromString(const std::string& string);