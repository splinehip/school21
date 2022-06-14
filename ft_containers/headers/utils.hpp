#pragma once
#include <typeinfo>

#include "iterators.hpp"

namespace ft
{
template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare (
    InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1)
    {
        if (first2 == last2 || *first1 > *first2)
            return false;
        else if (*first1 < *first2)
            return true;
        first1++;
        first2++;
    }
    return first2 != last2;
}

template <typename InputIterator1, typename InputIterator2, typename Comp>
bool lexicographical_compare (
    InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Comp comp)
{
    while (first1 != last1)
    {
        if (first2 == last2 || comp(*first2, *first1))
            return false;
        else if (comp(*first1, *first2))
            return true;
        first1++;
        first2++;
    }
    return first2 != last2;
}

template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1)
    {
        if (first2 == last2 || *first1 != *first2)
            return false;
        first1++;
        first2++;
    }
    return true;
}

template <typename InputIterator1, typename InputIterator2, typename Comp>
bool equal(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Comp comp)
{
    while (first1 != last1)
    {
        if (first2 == last2 || comp(*first1, *first2))
            return false;
        first1++;
        first2++;
    }
    return true;
}

template<bool B, typename NotConst, typename Const>
struct conditional {typedef NotConst   type;};

template<typename NotConst, typename Const>
struct conditional<true, NotConst, Const> {typedef Const   type;};

template<bool B, typename NotConst, typename Const>
struct conditional_t
{typedef typename conditional<B, NotConst, Const>::type   type;};


template<bool B, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T> { typedef T type; };


template<typename T, typename U>
bool    is_same_type(const T &f, const U &s)
{
    return typeid(f) == typeid(s);
}

template<typename T, typename U>
struct is_same {static const bool value = false;};

template<typename T>
struct is_same<T, T> {static const bool value = true;};


template<typename Iterator, typename IteratorTag>
struct IsSameIter
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<is_same<IteratorTag, iter_category>::value>
    ::type  type;
};


template<typename Iterator>
struct IsOutputIter
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::output_iterator_tag, iter_category>::value>::type  type;
};

template<typename Iterator>
struct IsRandomIter
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::random_access_iterator_tag, iter_category>::value>::type  type;
};

template<typename Iterator>
struct IsBiDirIter
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::bidirectional_iterator_tag, iter_category>::value
    || is_same<std::random_access_iterator_tag, iter_category>::value>
        ::type  type;
};

template<typename Iterator>
struct IsForwardIter
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::forward_iterator_tag, iter_category>::value
    || is_same<std::bidirectional_iterator_tag, iter_category>::value
    || is_same<std::random_access_iterator_tag, iter_category>::value>
        ::type  type;
};

template<typename Iterator>
struct IsInputIter
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::input_iterator_tag, iter_category>::value
    || is_same<std::forward_iterator_tag, iter_category>::value
    || is_same<std::bidirectional_iterator_tag, iter_category>::value
    || is_same<std::random_access_iterator_tag, iter_category>::value>
        ::type  type;
};

}
