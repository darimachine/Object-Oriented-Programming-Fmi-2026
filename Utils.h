#pragma once
#include<string>
using namespace std;

struct Coordinates
{
	double x;
	double y;
};

enum class FeatureKind
{
	Volcano,
	Forest, 
	Lake, 
	Bog,
	Mountain,
	Desert
};

class Utils
{
public:
	static string convertFeatureToString(FeatureKind feature);
	static FeatureKind convertStringToFeature(const string& feature);
};