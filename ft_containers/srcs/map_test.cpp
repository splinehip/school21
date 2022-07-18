#include "map.hpp"

void    map_test(void)
{
    ft::map<int, std::string> m;
    ft::map<int, std::string> m2;

    ft::map<int, std::string>::iterator it;

    std::cout << "m empty: " << std::boolalpha << m.empty() << std::endl;
    std::cout << "m size: " << m.size() << std::endl;
    std::cout << "m max_size: " << m.max_size() << std::endl;

    std::cout << "m[10]: " << m[10] << std::endl;
    std::cout << "m size: " << m.size() << std::endl;
    std::cout << "m[10] = KUUUUU: " << (m[10] = "KUUUUU") << std::endl;
    std::cout << "m size: " << m.size() << std::endl;
    std::cout << "m.swap(m2)" << std::endl;
    m.swap(m2);
    std::cout << "m size: " << m.size() << std::endl;
    std::cout << "m2 size: " << m2.size() << std::endl;
    std::cout << "m2[10]: " << m2[10] << std::endl;
    ft::pair<typename ft::map<int, std::string>::iterator, bool> insert_res;
    insert_res = m.insert(ft::make_pair<int, std::string>(44, "FUUUUUU"));
    std::cout << "m insert: " << insert_res.first->second
        << std::boolalpha << ", " << insert_res.second << std::endl;
    insert_res = m.insert(ft::make_pair<int, std::string>(44, "FUUUUUU"));
    std::cout << "m insert: " << insert_res.first->second
        << std::boolalpha << ", " << insert_res.second << std::endl;
    it = m.insert(m.end(), ft::make_pair<int, std::string>(45, "FUUUUUU"));
    std::cout << "m insert position: " << it->first
        << ", " << it->second << std::endl;
    it = m.insert(m.end(), ft::make_pair<int, std::string>(45, "TTTTTTTT"));
    std::cout << "m insert position: " << it->first
        << ", " << it->second << std::endl;

    std::map<int, std::string> sm;
    sm[10] = "HHHHHHHHHH";
    std::cout << "sm.insert(it, val): " << sm.insert(sm.begin(),
        std::make_pair<int, std::string>(10, "KKKKKKK"))->second << std::endl;

    m2[30] = "DDDDD";
    m2[40] = "SSSSSSSS";
    m2[1] = "LLLLLL";
    m.insert(m2.begin(), m2.end());
    std::cout << "m after insert iter range:" << std::endl;
    it = m.begin();
    while (it != m.end())
    {
        std::cout << "key: " << it->first
        << ", val: " << it->second << std::endl;
        ++it;
    }

    sm[20] = "PPPPPP";
    sm[100] = "QQQQQQQQQ";
    m.insert(sm.begin(), sm.end());
    std::cout << "m after insert iter range from sm:" << std::endl;
    it = m.begin();
    while (it != m.end())
    {
        std::cout << "key: " << it->first
        << ", val: " << it->second << std::endl;
        ++it;
    }
    m.erase(m.begin(), m.end());
    m[0] = "TTTTTTTTT";
    std::cout << "m after erase and insert one element:" << std::endl;
    it = m.begin();
    while (it != m.end())
    {
        std::cout << "key: " << it->first
        << ", val: " << it->second << std::endl;
        ++it;
    }

}
