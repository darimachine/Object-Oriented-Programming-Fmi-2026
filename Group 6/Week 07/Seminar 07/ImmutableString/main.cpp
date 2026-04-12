#include <iostream>
#include "ImmutableString.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{

    ImmutableString s1 = "Hello";
    ImmutableString s2 = "Hello";
   // cout<<s2.getRefCount()<<endl;
    ImmutableString s3 = "abc";
    //cout << (s1 == s3);
    ImmutableString::print();
}
