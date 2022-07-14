#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>

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

    /* for (int i = 0; i < 300; i++)
    {
        int key = rand() % 1000;
        std::cout << "rbtree.insert(" << key << ", empty)" << std::endl;
        rbtree.insert(key, "empty");
        rbtree.print();
        rbtree.checkBalance();
    } */
/*     while (rbtree.size() != 0)
    {
        int key = rand() % 1000;
        if (rbtree.find(key) != NULL)
        {
            std::cout << "rbtree.remove(" << key << ")" << std::endl;
            rbtree.remove(key);
            rbtree.print();
            rbtree.checkBalance();
        }
    } */

    std::map<int, std::string> m;

    for (int i = 1; i < 11; i++)
    {
        rbtree.insert(i, "empty");
        m[i] = "empty";
    }
    //rbtree.print();
    /* for (int i = 1; i < 11000; i++)
    {
        m[i] = "empty";
    } */

    ft::RBTree<ft::pair<const int, std::string> >::iterator it = rbtree.begin();
    ft::RBTree<ft::pair<const int, std::string> >::iterator ite = rbtree.end();
    std::map<int, std::string>::iterator mit = m.begin();
    std::map<int, std::string>::iterator mite = m.end();
    /* rbtree.insert(0, "empty");
    m[0] = "empty"; */
    /* std::cout << "mit->first: " << mit->first
        << " mit->second: " << mit->second << "\t"
        << "ite->first " << it->first << " it->second: " << it->second << std::endl; */
    //mit = m.begin();
    /* --mit;
    std::cout << "mit->first: " << mit->first
        << " mit->second: " << mit->second << "\t"
        << "ite->first " << it->first << " it->second: " << it->second << std::endl; */

    //rbtree.insert(-1, "");
    /* std::cout << "mit->first: " << mit->first
        << " mit->second: " << mit->second << std::endl;
    std::cout << "mite->first: " << mite->first
        << " mite->second: " << mite->second << std::endl;
    std::cout << "it->first: " << it->first
        << " it->second: " << it->second << std::endl;
    std::cout << "ite->first: " << ite->first
        << " ite->second: " << ite->second << std::endl;
    std::cout << std::endl; */

    //it = ite;
    /* std::cout << " it == ite: " << std::boolalpha << (it == ite) << std::endl;
    std::cout << it->first << " it != ite: " << std::boolalpha << (it != ite) << std::endl;
    ++it; ++it;
    std::cout << " it == ite: " << std::boolalpha << (it == ite) << std::endl;
    std::cout << it->first << " it != ite: " << std::boolalpha << (it != ite) << std::endl;
    while (it != ite)
    {
        std::cout << it->first << " it != ite: " << std::boolalpha << (it != ite) << std::endl;
        ++it;
    } */
    //std::cout << std::endl;
    //mit = m.begin();
    //it = rbtree.begin();
    /* m[11] = "GGGGGG";
    while (mit != mite)
    {
        std::cout << "mit->first: " << mit->first
        << " mit->second: " << mit->second << std::endl;
        ++mit;
    } */
    //m[12] = "KKKKKKKK";
    //m[14] = "KKKKKKKK";
    //rbtree.insert(12, "JJJJJJJJJ");
    //rbtree.insert(14, "JJJJJJJJJ");
    while (it != ite)
    {
        std::cout << "mit->first: " << mit->first
        << " mit->second: " << mit->second << "\t"
        << "it->first: " << it->first
        << " it->second: " << it->second << std::endl;
        ++it;
        ++mit;
    }
    std::cout << "\nreverse" << std::endl;
    mit = m.begin();
    it = rbtree.begin();
    //m[11] = "GGGGGGG";
    //rbtree.insert(11, "HHHHHHH");
    //ite = rbtree.end();
    while (ite != it)
    {
        std::cout << "mite->first: " << mite->first
        << " mite->second: " << mite->second << "\t"
        << "ite->first: " << ite->first
        << " ite->second: " << ite->second << std::endl;
        --ite;
        --mite;
    }

    ft::RBTree<ft::pair<const int, std::string> >::reverse_iterator rit = rbtree.rbegin();
    ft::RBTree<ft::pair<const int, std::string> >::reverse_iterator rite = rbtree.rend();
    std::map<int, std::string>::reverse_iterator mrit = m.rbegin();
    //std::map<int, std::string>::reverse_iterator mrite = m.rend();
    std::cout << "\nreverse iter:" << std::endl;
    while (rit != rite)
    {
        std::cout << "mrit->first: " << mrit->first
        << " mrit->second: " << mrit->second << "\t"
        << "rit->first: " << rit->first
        << " rit->second: " << rit->second << std::endl;
        ++rit;
        ++mrit;
    }

    /* while (mite != mit)
    {
        std::cout << "mite->first: " << mite->first
        << " mite->second: " << mite->second << std::endl;
        --mite;
    } */
    /* std::cout << "\nreverse:" << std::endl;
    it = rbtree.begin();
    mite = m.end(); */
    //m[0] = "empty";
    //rbtree.insert(0, "empty");
    /* while (mite != mit)
    {
        std::cout << "mite->first: " << mite->first
        << " mite->second: " << mite->second << std::endl;
        --mite;
    } */


    /* ft::RBTree<ft::pair<const int, std::string> >::iterator it2 = rbtree.begin();
    std::cout << "it == it2: " << std::boolalpha << (it == it2) << std::endl;
    std::cout << "it != it2: " << std::boolalpha << (it != it2) << std::endl;
    it++;
    std::cout << "it++\nit->first: " << it->first
        << " it->second: " << it->second << std::endl;
    ++it;
    std::cout << "++it\nit->first: " << it->first
        << " it->second: " << it->second << std::endl;

    it--;
    std::cout << "it--\nit->first: " << it->first
        << " it->second: " << it->second << std::endl;
    --it;
    std::cout << "--it\nit->first: " << it->first
        << " it->second: " << it->second << std::endl; */

    //interactive(rbtree);
}
