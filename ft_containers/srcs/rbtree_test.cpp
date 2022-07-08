#include <iostream>
#include <unistd.h>

#include "rbtree.hpp"

void    rbtree_test(void)
{
    ft::pair<int, std::string>  data = ft::make_pair<int, std::string>(10, "KUKU");
    ft::RBTree<int, std::string> rbtree;

    std::cout << "rbtree.insert(10, \"KUKU\")" << std::endl;
    rbtree.insert(data);

    std::cout << "rbtree.insert(20, \"PUPU\")" << std::endl;
    rbtree.insert(20, "PUPU");

    std::cout << "rbtree.insert(8, \"TUPU\")" << std::endl;
    rbtree.insert(8, "TUPU");

    std::cout << "rbtree.insert(5, \"LUPU\")" << std::endl;
    rbtree.insert(5, "LUPU");

    std::cout << "rbtree.insert(9, \"TUPU\")" << std::endl;
    rbtree.insert(9, "TUPU");

    std::cout << "rbtree.insert(4, \"LUPU\")" << std::endl;
    rbtree.insert(4, "LUPU");

    std::cout << "rbtree.insert(3, \"LUPU\")" << std::endl;
    rbtree.insert(3, "LUPU");

    std::cout << "rbtree.insert(40, \"KUPU\")" << std::endl;
    rbtree.insert(40, "KUPU");

    std::cout << "rbtree.insert(25, \"DUPU\")" << std::endl;
    rbtree.insert(25, "DUPU");

    std::cout << "rbtree.remove(3)" << std::endl;
    rbtree.remove(3);

    std::cout << "rbtree.remove(10)" << std::endl;
    rbtree.remove(10);

}
