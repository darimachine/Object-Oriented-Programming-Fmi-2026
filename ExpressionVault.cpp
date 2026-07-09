#include "ExpressionVault.h"
#include<iostream>
#include<fstream>
#include<stdexcept>

void ExpressionVault::add(unique_ptr<IExpression> expression)
{
	expressions.push_back(move(expression));
	used.push_back(false);
}

void ExpressionVault::makeTest(unsigned tasksCount, const string& testName)
{
	ofstream file(testName);
	if (!file.is_open())
	{
		throw runtime_error("Cannot open the file.");
	}

	for (unsigned i = 0;i < tasksCount;i++)
	{
		size_t index = 0;
		cin >> index;

		if (index >= expressions.size())
		{
			throw out_of_range("Index is out of range.");
		}

		if (used[index])
		{
			throw logic_error("Expression already used in another test.");
		}

		file << expressions[index]->toString() << '\n';
		used[index] = true;
		history.push_back(index);
	}
	file.close();
}

void ExpressionVault::listAll()const
{
	for (size_t i = 0;i < expressions.size();i++)
	{
		cout << i << " - " << expressions[i]->toString() << '\n';
	}
}

void ExpressionVault::listAllUsed()const
{
	for (size_t i = 0;i < used.size();i++)
	{
		if (used[i])
		{
			cout << expressions[i]->toString() << '\n';
		}
	}
}

void ExpressionVault::listAllNotUsed()const
{
	for (size_t i = 0;i < used.size();i++)
	{
		if (!used[i])
		{
			cout << expressions[i]->toString() << '\n';
		}
	}
}

void ExpressionVault::solveAll()const
{
	for (size_t i = 0;i < expressions.size();i++)
	{
		cout << i << " - " << expressions[i]->toString() << " = " <<
			expressions[i]->eval() << '\n';
	}
}

void ExpressionVault::markInvalid()
{
	for (size_t i = 0;i < expressions.size();i++)
	{
		if (expressions[i]->isTrivial())
		{
			used[i] = true;
		}
	}
}

void ExpressionVault::showHistory()const
{
	if (history.empty())
	{
		return;
	}

	for (size_t index:history)
	{
		cout << expressions[index]->toString() << '\n';
	}
}