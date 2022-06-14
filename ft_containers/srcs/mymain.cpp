#include <iostream>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <vector.hpp>
#include <vector>

#include "iterators.hpp"

class Mymain
{
private:
    std::string name;
public:
    Mymain(): name(""){}
    Mymain(const std::string &_name): name(_name){}
    const Mymain& operator=(const Mymain&)const{return *this;}
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
    std::cout << "IterAssign: " << "my.size: " << my.size() << " cap: " << my.capacity() << std::endl;
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
  std::cout << "\nswap(foo, bar)\n";

  swap(foo, bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
    my.at(1);
    const Mymain &ref = my.at(1);
    std::cout << "const Mymain &ref: "; ref.printName();
    std::cout << "foo == bar = " << std::boolalpha << (foo == bar) << std::endl;
    std::cout << "foo != bar = " << std::boolalpha << (foo != bar) << std::endl;
    foo = bar;
    std::cout << "foo = bar: foo == bar = "
        << std::boolalpha << (foo == bar) << std::endl;
    std::cout << "foo != bar = " << std::boolalpha << (foo != bar) << std::endl;
    //std::cout << "foo != bar = " << std::boolalpha << (foo < bar) << std::endl;
    std::vector<int> vv(10, 100);
    std::vector<int>::iterator it = vv.begin();
    ft::advance(it, 5);
    it[1] = 34;
    std::cout << "DDD: " << *((1 + it).base()) << " dis: " << ft::distance(it, vv.end()) << std::endl;
    std::vector<Mymain> cc(10, Mymain("KRAYA"));
    std::vector<Mymain>::iterator itb = cc.begin();
    itb->printName();

    ft::vector<int> bb(10, 100);
    ft::vector<int>::iterator itt;
    ft::vector<int>::const_iterator ittc;
    itt = bb.begin();
    bb[1] = 141414;
    ft::advance(itt, 1);
    ft::vector<int>::iterator itt2(itt);
    *itt2 = 500;
    std::cout << "*itt " << *itt << " dis: " << ft::distance(itt, bb.end()) << std::endl;
    std::cout << "*itt2++ " << *itt2++ << " dis: " << ft::distance(itt2, bb.end()) << std::endl;
    std::cout << "*itt2 " << *itt2 << " dis: " << ft::distance(itt2, bb.end()) << std::endl;
    bb[3] = 144;
    bb[4] = 45;
    std::cout << "++itt2 " << *(++itt2) << " dis: " << ft::distance(itt2, bb.end()) << std::endl;
    std::cout << "itt2 " << itt2[0] << " dis: " << ft::distance(itt2, bb.end()) << std::endl;
    std::cout << "*(1 + itt2) " << *(1 + itt2) << " dis: " << ft::distance(itt2, bb.end()) << std::endl;

    ft::vector<Mymain> ss(10, Mymain("KRAYA"));
    ft::vector<Mymain>::iterator  itsr = ss.begin();
    ft::vector<Mymain>::const_iterator  itsc;
    ft::vector<Mymain>::const_iterator its = ss.cbegin();
    its->printName();
    itsc = itsr;
    itsc = its;
    itsc->printName();
    *its = Mymain("ruururu");
    its->printName();
    std::map<int, int> f;
    f[0] = 1;
    f[1] = 2;
    std::map<int, int>::iterator itf;

    std::cout << "itt == itt = " << std::boolalpha << (itt == itt) << std::endl;
    ittc = itt;
    //ittc[0] = 10;
    std::cout << "itt == ittc = " << std::boolalpha << (itt == ittc) << std::endl;
    std::cout << "itt != itt = " << std::boolalpha << (itt != itt) << std::endl;
    std::cout << "itt < itt = " << std::boolalpha << (itt < itt) << std::endl;
    std::cout << "itt <= itt = " << std::boolalpha << (itt <= itt) << std::endl;
    std::cout << "itt > itt = " << std::boolalpha << (itt > itt) << std::endl;
    std::cout << "itt >= itt = " << std::boolalpha << (itt >= itt) << std::endl;
    std::cout << "is_same(itt, itt) = " << std::boolalpha
      << ft::is_same<ft::vector<int>, ft::vector<int> >::value << std::endl;

    ft::vector<int> vi;
    vi.assign(bb.begin(), bb.end());
    std::cout << "vi.size: " << vi.size() << " v[0]: " << vi[0] << std::endl;
    return 0;
}
