#include "MyException.h"

const char* MyException::what() const
{
    if (e == "InvalidTypeData") {
        return "InvalidTypeData";
    }
    if (e == "NotPossibleUndo") {
        return "NotPossibleUndo";
    }
    if (e == "NotRightType") {
        return "NotRightType";
    }
    if (e == "RemoveLMNotPossible") {
        return "RemoveLMNotPossible";
    }
    if (e == "CannotAddCartographer")
    return "CannotAddCartographer";
}
