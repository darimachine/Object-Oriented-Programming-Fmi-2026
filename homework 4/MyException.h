#pragma once
#include <exception>
#include <string>
enum error {
	NotPossibleUndo,
	NotRightType,
	InvalidTypeData,
	RemoveLMNotPossible,
	CannotAddCartographer
};

class MyException : public std::exception
{
private:
	std::string e;
public:
	const char* what() const override;
	MyException(std::string e) : e(e) {};

};

