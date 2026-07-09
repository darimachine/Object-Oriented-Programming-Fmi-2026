#include "Component.h"

Component::Component(const string& label):label(label){}

const string& Component::getLabel()const
{
	return label;
}