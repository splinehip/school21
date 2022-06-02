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
    void printName() const {std::cout << name << std::endl;}
};

int main(void)
{
    ft::vector<std::string> v;
    ft::vector<std::string> vc;
    ft::vector<Mymain> my;
    std::vector<Mymain> stdmy;

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
    my.resize(5);
    my.resize(8, Mymain("KUKU"));
    std::cout << "my.size: " << my.size() << " cap: " << my.capacity() << std::endl;
    for (size_t i = 0; i < my.size(); i++)
    {
        my[i].printName();
    }
    vc.reserve(100);
    std::cout << "vc.size: " << vc.size() << " cap: " << vc.capacity() << std::endl;
    std::cout << vc[0] << std::endl;
    std::cout << vc[1] << std::endl;
    vc.shrink_to_fit();
    std::cout << "vc.size: " << vc.size() << " cap: " << vc.capacity() << std::endl;

    my.assign(10, vc[0]);
    std::cout << "my.size: " << my.size() << " cap: " << my.capacity() << std::endl;
    for (size_t i = 0; i < my.size(); i++)
    {
        my[i].printName();
    }

    stdmy.push_back(Mymain("One"));
    stdmy.push_back(Mymain("Two"));
    my.assign(stdmy.begin(), stdmy.end());
    std::cout << "my.size: " << my.size() << " cap: " << my.capacity() << std::endl;
    for (size_t i = 0; i < my.size(); i++)
    {
        my[i].printName();
    }
    ft::vector<Mymain> my2(3, Mymain("TRUE"));
    std::cout << "my2.size: " << my2.size() << " cap: " << my2.capacity() << std::endl;
    for (size_t i = 0; i < my2.size(); i++)
    {
        my2[i].printName();
    }

  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  //int *it = &foo[0];
  //std::cout << it << ": " << *it << std::endl;

  //std::cout << it++ << ": " << *it << std::endl;
  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << "\nfoo.swap(bar)\n";

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
    my.at(100);
    return 0;
}
