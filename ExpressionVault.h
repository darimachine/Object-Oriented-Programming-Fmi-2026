#pragma once
#include"IExpression.h"
#include<memory>
#include<vector>

class ExpressionVault
{
private:
	vector<unique_ptr<IExpression>> expressions;
	vector<bool> used;
	vector<size_t> history;

public:
	ExpressionVault() = default;

	void add(unique_ptr<IExpression> expression);
	void makeTest(unsigned tasksCount, const string& testName);
	void listAll()const;
	void listAllUsed()const;
	void listAllNotUsed()const;
	void solveAll()const;
	void markInvalid();
	void showHistory()const;
};

