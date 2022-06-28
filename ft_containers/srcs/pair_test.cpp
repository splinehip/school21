#include <iostream>
#include <iomanip>

#include <pair.hpp>

void    pair_test(void)
{
    std::cout << "pair: init default: ft::pair<std::string, int> p" << std::endl;
    ft::pair<std::string, int>  p;
    std::cout << "p.first: " << p.first << ", p.second: " << p.second << std::endl << std::endl;

    std::cout << "pair: init param: ft::pair<std::string, int>  p2(\"TEST\", 100)" << std::endl;
    ft::pair<std::string, int>  p2("TEST", 100);
    std::cout << "p2.first: " << p2.first << ", p2.second: " << p2.second << std::endl << std::endl;

    std::cout << "pair: p = make_pair(\"test\", 10)" << std::endl;
    p = ft::make_pair("test", 10);
    std::cout << "p.first: " << p.first << ", p.second: " << p.second << std::endl << std::endl;

    std::cout << "pair: compaire operators" << std::endl;
    std::cout << "p == p2: " << std::boolalpha << (p == p2) << std::endl;
    std::cout << "p != p2: " << std::boolalpha << (p != p2) << std::endl;
    std::cout << "p < p2: " << std::boolalpha << (p < p2) << std::endl;
    std::cout << "p <= p2: " << std::boolalpha << (p <= p2) << std::endl;
    std::cout << "p > p2: " << std::boolalpha << (p > p2) << std::endl;
    std::cout << "p >= p2: " << std::boolalpha << (p >= p2) << std::endl;

}
