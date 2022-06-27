#include <iostream>
#include <iomanip>

#include <stack.hpp>

void    stack_test(void)
{
    std::cout << "init stack<int>" << std::endl;
    ft::stack<int> sint;

    std::cout << "stack is empty: " << std::boolalpha << sint.empty() << std::endl;
    std::cout << "stack size: " << sint.size() << std::endl;
    std::cout << "stack 3 push: 10, 20, 30" << std::endl;
    sint.push(10);
    sint.push(20);
    sint.push(30);
    std::cout << "stack is empty: " << std::boolalpha << sint.empty() << std::endl;
    std::cout << "stack size: " << sint.size() << std::endl;
    std::cout << "stack top: " << sint.top() << std::endl << std::endl;

    std::cout << "stack pop" << std::endl;
    sint.pop();
    std::cout << "stack is empty: " << std::boolalpha << sint.empty() << std::endl;
    std::cout << "stack size: " << sint.size() << std::endl;
    std::cout << "stack top: " << sint.top() << std::endl << std::endl;

    std::cout << "init second stack int" << std::endl;
    ft::stack<int> sint_2;
    std::cout << "swap(sint, sint_2)" << std::endl;
    ft::swap(sint, sint_2);
    std::cout << "stack sint is empty: " << std::boolalpha << sint.empty() << std::endl;
    std::cout << "stack sint_2 is empty: " << std::boolalpha << sint_2.empty() << std::endl;
    std::cout << "stack sint size: " << sint.size() << std::endl;
    std::cout << "stack sint_2 size: " << sint_2.size() << std::endl;
    std::cout << "stack sint_2 top: " << sint_2.top() << std::endl << std::endl;

    std::cout << "stack sint = stack<int>(sint_2)" << std::endl;
    sint = ft::stack<int>(sint_2);
    std::cout << "stack is empty: " << std::boolalpha << sint.empty() << std::endl;
    std::cout << "stack size: " << sint.size() << std::endl;
    std::cout << "stack top: " << sint.top() << std::endl << std::endl;

    std::cout << "stack sint.push(50)" << std::endl;
    sint.push(50);
    std::cout << "stack sint is empty: " << std::boolalpha << sint.empty() << std::endl;
    std::cout << "stack sint_2 is empty: " << std::boolalpha << sint_2.empty() << std::endl;
    std::cout << "stack sint size: " << sint.size() << std::endl;
    std::cout << "stack sint_2 size: " << sint_2.size() << std::endl;
    std::cout << "stack sint top: " << sint.top() << std::endl;
    std::cout << "stack sint_2 top: " << sint_2.top() << std::endl << std::endl;

    std::cout << "stack: ft::vector<int> vint(10, 30): sint = ft::stack<int>(vint)" << std::endl;
    ft::vector<int> vint(10, 30);
    sint = ft::stack<int>(vint);
    std::cout << "stack is empty: " << std::boolalpha << sint.empty() << std::endl;
    std::cout << "stack size: " << sint.size() << std::endl;
    std::cout << "stack top: " << sint.top() << std::endl << std::endl;

    std::cout << "stack: compaire operators sint and sint_2" << std::endl;
    std::cout << "sint == sint_2: " << std::boolalpha << (sint == sint_2) << std::endl;
    std::cout << "sint != sint_2: " << std::boolalpha << (sint != sint_2) << std::endl;
    std::cout << "sint > sint_2: " << std::boolalpha << (sint > sint_2) << std::endl;
    std::cout << "sint >= sint_2: " << std::boolalpha << (sint >= sint_2) << std::endl;
    std::cout << "sint < sint_2: " << std::boolalpha << (sint < sint_2) << std::endl;
    std::cout << "sint <= sint_2: " << std::boolalpha << (sint <= sint_2) << std::endl;
}
