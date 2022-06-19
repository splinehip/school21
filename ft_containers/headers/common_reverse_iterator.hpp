/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:32:50 by cflorind          #+#    #+#             */
/*   Updated: 2022/06/19 16:07:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"
#include "utils.hpp"

namespace ft
{
template<typename Iterator>
struct common_reverse_iterator
{
typedef typename Iterator::iterator_category   iterator_category;
typedef typename Iterator::value_type          value_type;
typedef typename Iterator::difference_type     difference_type;
typedef typename Iterator::pointer             pointer;
typedef typename Iterator::reference           reference;

typedef common_reverse_iterator<Iterator>      iter_t;
typedef iter_t                                 iterator_type;

private:
    typedef typename iterator_traits<Iterator>::value_type      value_t;
    typedef typename iterator_traits<Iterator>::difference_type diff_t;

    Iterator iter;

public:
    common_reverse_iterator(void){};
    common_reverse_iterator(const Iterator &_iter, int){iter = _iter;}
    common_reverse_iterator(const iter_t &_iter){*this = _iter;}
    ~common_reverse_iterator(void){};

    iter_t  &operator=(const iter_t &inst)
    {
        std::cout << "iter_t" << std::endl;
        if (this == &inst)
            return *this;
        iter = inst.base();
        return *this;
    }

    template<typename Iter>
    iter_t  &operator=(const common_reverse_iterator<Iter> &inst)
    {
        std::cout << "common_reverse_iterator<Iter>" << std::endl;
        if (iter == inst.base())
            return *this;
        iter = inst.base();
        return *this;
    }

    iter_t  operator+(diff_t n) const {return iter_t(iter - n);}
    iter_t  operator-(diff_t n) const {return iter_t(iter + n);}
    diff_t  operator-(iter_t &rhs) const {return iter + rhs.item;}

    iter_t  &operator+=(diff_t n){iter -= n; return *this;}
    iter_t  &operator-=(diff_t n) {iter += n; return *this;}

    iter_t  &operator++(void){--iter; return *this;}
    iter_t  operator++(int){return iter_t(iterator(iter--));}
    iter_t  &operator--(void){++iter; return *this;}
    iter_t  operator--(int){return iter_t(iterator(iter++));}

    value_t operator*(void) const {return *iter;}
    value_t *operator->(void) const {return &(*iter);}
    value_t &operator[](diff_t n) const {return iter[n];}

    Iterator    base(void) const {return iter;}

    void    swap(iter_t &rhs){Iterator &tmp = iter;
                                iter = rhs.iter; rhs.iter = tmp;}

};

}
