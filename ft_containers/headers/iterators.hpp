#pragma once
#include <cstddef>
#include <iterator>

namespace ft
{
template<typename Category, typename T, typename Distance = ptrdiff_t,
    typename Pointer = T*, typename Reference = T&>
struct iterator_base
{
typedef Category        iterator_category;
typedef T               value_type;
typedef Distance        difference_type;
typedef Pointer         pointer;
typedef Reference       reference;

};

template<typename Iterator>
struct iterator_traits
{
typedef typename Iterator::iterator_category    iterator_category;
typedef typename Iterator::value_type           value_type;
typedef typename Iterator::difference_type      difference_type;
typedef typename Iterator::pointer              pointer;
typedef typename Iterator::reference            reference;

};

template<typename T>
struct iterator_traits<T*>
{
typedef std::random_access_iterator_tag iterator_category;
typedef T                               value_type;
typedef ptrdiff_t                       difference_type;
typedef T*                              pointer;
typedef T&                              reference;

};

template<typename T>
struct iterator_traits<const T*>
{
typedef std::random_access_iterator_tag iterator_category;
typedef T                               value_type;
typedef ptrdiff_t                       difference_type;
typedef const T*                        pointer;
typedef const T&                        reference;

};

template<typename Iterator>
typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&)
{
    typedef typename iterator_traits<Iterator>::iterator_category category;
    return category();
}

//Distance:
template<typename InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance_impl(InputIterator first, InputIterator last, std::input_iterator_tag)
{
    typename iterator_traits<InputIterator>::difference_type n = 0;

    while (first++ != last)
        n++;
    return n;
}

template<typename RandomAccessIterator>
typename iterator_traits<RandomAccessIterator>::difference_type
distance_impl(RandomAccessIterator first, RandomAccessIterator last,
        std::random_access_iterator_tag)
{
    return last - first;
}

template<typename InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last)
{
    return distance_impl(first, last, iterator_category(first));
}

//Advance:
template<typename InputIterator, typename Distance>
void advance_impl(InputIterator &iter, Distance d, std::input_iterator_tag)
{
    if (d < 0)
        throw std::out_of_range("Negative distance");
    while (d--) ++iter;
}

template<typename BidirectionalIterator, typename Distance>
void advance_impl(
    BidirectionalIterator &iter, Distance d, std::bidirectional_iterator_tag)
{
    if (d >= 0)
        while (d--) ++iter;
    else
        while (d++) --iter;
}

template<typename RandomAccessIterator, typename Distance>
void advance_impl(RandomAccessIterator &iter, Distance d,
    std::random_access_iterator_tag)
{
    iter += d;
}

template<typename InputIterator, typename Distance>
void advance(InputIterator &iter, Distance d)
{
    advance_impl(iter, d, iterator_category(iter));
}

//Iterators common operators overload:
template<typename IteratorF, typename IteratorS>
bool    operator_eq_impl(const IteratorF f, const IteratorS s,
    std::random_access_iterator_tag, std::random_access_iterator_tag)
{
    return f.base() == s.base();
}

template<typename IteratorF, typename IteratorS>
bool    operator_less_impl(const IteratorF f, const IteratorS s,
    std::random_access_iterator_tag, std::random_access_iterator_tag)
{
    return f.base() < s.base();
}

template<typename IteratorF, typename IteratorS>
bool    operator_less_eq_impl(const IteratorF f, const IteratorS s,
    std::random_access_iterator_tag, std::random_access_iterator_tag)
{
    return f.base() <= s.base();
}

template<typename IteratorF, typename IteratorS>
bool    operator==(const IteratorF f, const IteratorS s)
{
    return operator_eq_impl(f, s, iterator_category(f), iterator_category(s));
}

template<typename IteratorF, typename IteratorS>
bool    operator!=(const IteratorF f, const IteratorS s)
{
    return !operator_eq_impl(f, s, iterator_category(f), iterator_category(s));
}

template<typename IteratorF, typename IteratorS>
bool    operator<(const IteratorF f, const IteratorS s)
{
    return operator_less_impl(f, s, iterator_category(f), iterator_category(s));
}

template<typename IteratorF, typename IteratorS>
bool    operator>(const IteratorF f, const IteratorS s)
{
    return operator_less_impl(s, f, iterator_category(f), iterator_category(s));
}

template<typename IteratorF, typename IteratorS>
bool    operator<=(const IteratorF f, const IteratorS s)
{
    return operator_less_eq_impl(f, s, iterator_category(f), iterator_category(s));
}

template<typename IteratorF, typename IteratorS>
bool    operator>=(const IteratorF f, const IteratorS s)
{
    return operator_less_eq_impl(s, f, iterator_category(f), iterator_category(s));
}

template<typename Iterator>
Iterator   operator+(
    const typename Iterator::difference_type n, const Iterator &iter)
{
    return iter + n;
}

}
