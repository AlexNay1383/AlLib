#include <iostream>
#include <string>
#include "string.hpp"

int main()
{
    String a, b = "Hello";
    const String c = b;
    a = "Char";
    a = b;
    a += b;

    std::cout << a;

    return 0;
}