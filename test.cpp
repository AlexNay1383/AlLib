#include "String/string.hpp"

int main()
{
    String str = "Hello";

    str[4] = '0';

    std::string end = ", world!";

    String result = str + end;
    result += result + end + str;

    std::cout << result << std::endl;

    return 0;
}