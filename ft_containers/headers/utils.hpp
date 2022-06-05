#pragma once

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

}
