#include <iostream>
#include <sstream>

#include <rbtree.hpp>

template<typename Data>
void    interactive(ft::RBTree<Data> &rbtree)
{
    std::string cmd;
    int key;
    std::string value;
    std::string in;
    std::stringstream s;
    std::cout << "RBTree" << std::endl;
	std::cout << "Available command: add, find, rm, exit" << std::endl;
	while (true)
	{
		std::cout << "> ";
		std::cin >> cmd;
		if (cmd == "add")
		{
            getline(std::cin, in);
            s << in;
            if (!(s >> key))
            {
			    std::cout << "key: ";
                std::cin >> key;
            }
			if (!(s >> value))
            {
			    std::cout << "value: ";
                std::cin >> value;
            }
			rbtree.insert(key, value);
            s.clear();
		}
		else if (cmd == "find")
		{
            std::cout << "key: ";
			std::cin >> key;
            Data *data = rbtree.find(key);
			if (data)
                std::cout << data->first << " res: " << data->second << std::endl;
            else
                std::cout << key << " res: NULL" << std::endl;
		}
        else if (cmd == "rm")
        {
            getline(std::cin, in);
            s << in;
            if (!(s >> key))
            {
			    std::cout << "key: ";
                std::cin >> key;
            }
			rbtree.remove(key);
        }
		else if (cmd == "exit")
        {
			return ;
        }
		else
		{
			std::cout << "Undefined command: " << cmd << std::endl;
			std::cout << "Available command: add, find, rm, exit" << std::endl;
		}
        rbtree.print();
    }
}

void    rbtree_test(void)
{
    ft::RBTree<ft::pair<const int, std::string> > rbtree;

    for (int i = 0; i < 300; i++)
    {
        int key = rand() % 1000;
        std::cout << "rbtree.insert(" << key << ", empty)" << std::endl;
        rbtree.insert(key, "empty");
        rbtree.print();
        rbtree.checkBalance();
    }
    while (rbtree.size() != 0)
    {
        int key = rand() % 1000;
        if (rbtree.find(key) != NULL)
        {
            std::cout << "rbtree.remove(" << key << ")" << std::endl;
            rbtree.remove(key);
            rbtree.print();
            rbtree.checkBalance();
        }
    }

    //interactive(rbtree);
}
