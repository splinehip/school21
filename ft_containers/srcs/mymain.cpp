#include <iostream>
#include <map>
#include <stdio.h>
#include <vector.hpp>
#include <vector>

class Mymain
{
private:
    std::string name;
public:
    Mymain(): name(""){}
    Mymain(const std::string &_name): name(_name){}
    ~Mymain(){};
    void printName(){std::cout << name << std::endl;}
};

int main(void)
{
    ft::vector<std::string> v;
    ft::vector<std::string> vc;
    ft::vector<Mymain> my;
    //std::vector<Mymain> my;


    v.push_back("10");
    std::cout << v[0] << std::endl;
    v.push_back("100");
    std::cout << v[1] << std::endl;
    std::map<std::string, float> m;
    m["ku"] = 10.0;
    std::cout << m["puk"] << std::endl;
    if (m.find("puk") != m.end())
        std::cout << "PUK\n";
    vc = v;
    std::cout << vc[0] << std::endl;
    std::cout << vc[1] << std::endl;
    std::cout << my.size() << std::endl;
    my.push_back(Mymain("Petya"));
    std::cout << my.size() << std::endl;
    my.push_back(Mymain("Vasya"));
    std::cout << my.size() << std::endl;
    my[0].printName();
    my[1].printName();
    for (int i = 0; i < 100000; i++)
    {
        char tmp[10];
        sprintf(tmp, "%i", i);
        std::string name = "Name: " + std::string(tmp);
        my.push_back(Mymain(name));
        //my[i+2].printName();
    }
    return 0;
}
