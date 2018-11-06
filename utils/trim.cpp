#include <string>
#include <iostream>

std::string trim(const std::string& s)
{
    auto l = s.cbegin(), r = s.cend() - 1;
    while (l < r && std::isspace(*l)) ++l;
    while (l < r && std::isspace(*r)) --r;
    return s.substr(l - s.cbegin(), r - l + 1);
}

int main()
{
    std::cout << "[" << trim("  123  @") << "]" << std::endl;
    std::cout << "[" << trim("  123  @   ") << "]" << std::endl;
    std::cout << "[" << trim("123  @") << "]" << std::endl;
    return 0;
}
