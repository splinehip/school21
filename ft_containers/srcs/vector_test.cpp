/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:56:46 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/19 21:28:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <vector>

#include <vector.hpp>

class Mymain
{
protected:
    std::string name;
    int *p = NULL;
public:
    Mymain(): name(""), p(NULL){}
    Mymain(const Mymain &inst){*this = inst;}
    Mymain(const std::string &_name): name(_name), p(new int(10)){}
    Mymain& operator=(const Mymain &inst)
    {name = inst.name; if (p) delete p; p = new int(*inst.p); return *this;}
    ~Mymain(){delete p;}
    const std::string &getName(void) const {return name;}
    void printName() const {std::cout << name << std::endl;}

    bool    operator!=(const Mymain &s) const {return name != s.name;}
    bool    operator<(const Mymain &s) const {return name < s.name;}
    bool    operator<=(const Mymain &s) const {return name <= s.name;}
    bool    operator>(const Mymain &s) const {return name > s.name;}
    bool    operator>=(const Mymain &s) const {return name >= s.name;}
};

std::ostream    &operator<<(std::ostream &out, const Mymain &inst)
{
    out << inst.getName();
    return out;
}

template<typename T, typename Allocator>
void    printVec(ft::vector<T, Allocator> &v, std::string name)
{
    std::cout << name << ":\t";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << i << ": " << v[i] << ", ";
    std::cout << std::endl << std::endl;
}

void    vector_test(void)
{
    std::cout << "### FT::VECTOR: Init empty" << std::endl;
    std::cout << "init empty ft::vector<int> vint" << std::endl;
    ft::vector<int> vint;

    std::cout << "init empty ft::vector<Mymain> vMymain" << std::endl << std::endl;
    ft::vector<Mymain> vMymain;

    std::cout << "### FT::VECTOR: Init with args" << std::endl;
    std::cout << "init ft::vector<int> vint_2(10, 100)" << std::endl;
    ft::vector<int> vint_2(10, 100);
    printVec(vint_2, "vint_2");

    std::cout << "init ft::vector<Mymain> vMymain_2(10, Mymain(\"Mymain\"))" << std::endl;
    ft::vector<Mymain> vMymain_2(10, Mymain("Mymain"));
    printVec(vMymain_2, "vMymain_2");

    std::cout << "### FT::VECTOR: Init copy" << std::endl;
    std::cout << "init vint = vint_2" << std::endl;
    vint = vint_2;
    std::cout << std::endl;
    std::cout << "vint_2[0] = 145" << std::endl;
    vint_2[0] = 145;
    std::cout << "vint[0]: " << vint[0] << " vint_2[0]: " << vint_2[0] << std::endl;
    std::cout << std::endl;

    std::cout << "init vMymain = vMymain_2" << std::endl;
    vMymain = vMymain_2;
    std::cout << "vMymain_2[0] = Mymain(\"NewMymain\")" << std::endl;
    vMymain_2[0] = Mymain("NewMymain");
    std::cout << "vMymain[0]: " << vMymain[0] << " vMymain_2[0]: " << vMymain_2[0] << std::endl;
    std::cout << std::endl;

    std::cout << "### FT::VECTOR: at()" << std::endl;
    std::cout << "const int a = vint.at(10)" << std::endl;
    try
    {
        const int a = vint.at(10);
        (void)a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;

        std::cout << "const int a = vint.at(9)" << std::endl;
        const int a = vint.at(9);
        std::cout << "a: " << a << std::endl;
    }
    std::cout << std::endl;

    std::cout << "### FT::VECTOR: front()" << std::endl;
    std::cout << "vint.front(): " << vint.front() << std::endl << std::endl;

    std::cout << "### FT::VECTOR: back()" << std::endl;
    std::cout << "vint.back(): " << vint.back() << std::endl << std::endl;

    std::cout << "### FT::VECTOR: assign(iter&, iter&)" << std::endl;
    std::vector<int> stdv;
    std::cout << "stdv: ";
    for (int i = 0; i < 10; i++)
    {
        stdv.push_back(i);
        std::cout << stdv[i] << ", ";
    }
    std::cout << std::endl;

    std::cout << "vint.assign(stdv.begin(), stdv.end())" << std::endl;
    vint.assign(stdv.begin(), stdv.end());
    printVec(vint, "vint");

    std::cout << "### FT::VECTOR: assign(n, val&)" << std::endl;
    std::cout << "vMymain.assign(5, Mymain(\"NewMymain\"))" << std::endl;
    vMymain.assign(5, Mymain("NewMymain"));
    printVec(vMymain, "vMymain");

    std::cout << "### FT::VECTOR: push_back()" << std::endl;
    std::cout << "vint.push_back(1000)" << std::endl;
    vint.push_back(1000);
    std::cout << "vint.back(): " << vint.back() << std::endl << std::endl;

    std::cout << "### FT::VECTOR: pop_back()" << std::endl;
    std::cout << "vint.pop_back()" << std::endl;
    vint.pop_back();
    std::cout << "vint.back(): " << vint.back() << std::endl << std::endl;

    std::cout << "### FT::VECTOR: compaire operators" << std::endl;
    printVec(vint, "vint");
    printVec(vint_2, "vint_2");
    std::cout << "vint == vint_2: " << std::boolalpha << (vint == vint_2) << std::endl;
    std::cout << "vint != vint_2: " << std::boolalpha << (vint != vint_2) << std::endl;
    std::cout << "vint >= vint_2: " << std::boolalpha << (vint >= vint_2) << std::endl;
    std::cout << "vint <= vint_2: " << std::boolalpha << (vint <= vint_2) << std::endl;
    std::cout << "vint > vint_2: " << std::boolalpha << (vint > vint_2) << std::endl;
    std::cout << "vint < vint_2: " << std::boolalpha << (vint < vint_2) << std::endl << std::endl;

    printVec(vMymain, "vMymain");
    printVec(vMymain_2, "vMymain_2");
    std::cout << "vMymain == vMymain_2: " << std::boolalpha << (vMymain == vMymain_2) << std::endl;
    std::cout << "vMymain != vMymain_2: " << std::boolalpha << (vMymain != vMymain_2) << std::endl;
    std::cout << "vMymain >= vMymain_2: " << std::boolalpha << (vMymain >= vMymain_2) << std::endl;
    std::cout << "vMymain <= vMymain_2: " << std::boolalpha << (vMymain <= vMymain_2) << std::endl;
    std::cout << "vMymain > vMymain_2: " << std::boolalpha << (vMymain > vMymain_2) << std::endl;
    std::cout << "vMymain < vMymain_2: " << std::boolalpha << (vMymain < vMymain_2) << std::endl;
    std::cout << std::endl;
    std::cout << "vint = vint_2, vMymain = vMymain_2" << std::endl;
    vint = vint_2;
    vMymain = vMymain_2;

    printVec(vint, "vint");
    printVec(vint_2, "vint_2");
    std::cout << "vint == vint_2: " << std::boolalpha << (vint == vint_2) << std::endl;
    std::cout << "vint != vint_2: " << std::boolalpha << (vint != vint_2) << std::endl;
    std::cout << "vint >= vint_2: " << std::boolalpha << (vint >= vint_2) << std::endl;
    std::cout << "vint <= vint_2: " << std::boolalpha << (vint <= vint_2) << std::endl;
    std::cout << "vint > vint_2: " << std::boolalpha << (vint > vint_2) << std::endl;
    std::cout << "vint < vint_2: " << std::boolalpha << (vint < vint_2) << std::endl << std::endl;

    printVec(vMymain, "vMymain");
    printVec(vMymain_2, "vMymain_2");
    std::cout << "vMymain == vMymain_2: " << std::boolalpha << (vMymain == vMymain_2) << std::endl;
    std::cout << "vMymain != vMymain_2: " << std::boolalpha << (vMymain != vMymain_2) << std::endl;
    std::cout << "vMymain >= vMymain_2: " << std::boolalpha << (vMymain >= vMymain_2) << std::endl;
    std::cout << "vMymain <= vMymain_2: " << std::boolalpha << (vMymain <= vMymain_2) << std::endl;
    std::cout << "vMymain > vMymain_2: " << std::boolalpha << (vMymain > vMymain_2) << std::endl;
    std::cout << "vMymain < vMymain_2: " << std::boolalpha << (vMymain < vMymain_2) << std::endl;
}
