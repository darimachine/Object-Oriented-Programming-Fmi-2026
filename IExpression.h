#pragma once
#include<string>
using namespace std;

class IExpression
{
public:
	virtual double eval()const = 0;
	virtual string toString()const = 0;
	virtual bool isTrivial()const = 0;

	virtual ~IExpression() = default;
};

