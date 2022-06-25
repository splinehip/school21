#pragma once
#include <cstddef>
#include <iterator>

#include "utils.hpp"

namespace ft
{
//Common:
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
typedef typename Iterator::iterator_type               iterator_type;

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

//Reverse iterator common:
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

    common_reverse_iterator(const Iterator &_iter): iter(_iter){}

public:
    common_reverse_iterator(void){};
    common_reverse_iterator(value_t *endIterElem): iter(Iterator(endIterElem)){}
    common_reverse_iterator(const iter_t &_iter){*this = _iter;}
    ~common_reverse_iterator(void){};

    iter_t  &operator=(const iter_t &inst)
    {
        if (this == &inst)
            return *this;
        iter = inst.base();
        return *this;
    }

    template<typename Iter>
    iter_t  &operator=(const common_reverse_iterator<Iter> &inst)
    {
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
    iter_t  operator++(int){return iter_t(iter--);}
    iter_t  &operator--(void){++iter; return *this;}
    iter_t  operator--(int){return iter_t(iter++);}

    value_t operator*(void) const {return *iter;}
    value_t *operator->(void) const {return &(*iter);}
    value_t &operator[](diff_t n) const {return iter[n];}

    Iterator    base(void) const {return iter;}

    void    swap(iter_t &rhs){Iterator &tmp = iter;
                                iter = rhs.iter; rhs.iter = tmp;}

};


//Category:
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


//Lexicographical compaire:
template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare_impl(
    InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2,
    std::input_iterator_tag, std::input_iterator_tag)
{
    while (first1 != last1 && first2 != last2)
    {
        if (*first2 < *first1)
            return false;
        if (*first1 < *first2)
            return true;
        first1++;
        first2++;
    }
    return (first1 == last1) && (first2 != last2);
}

template <typename InputIterator1, typename InputIterator2, typename Comp>
bool lexicographical_compare_impl(
    InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Comp comp,
    std::input_iterator_tag, std::input_iterator_tag)
{
    while (first1 != last1 && first2 != last2)
    {
        if (comp(*first2, *first1))
            return false;
        if (comp(*first1, *first2))
            return true;
        first1++;
        first2++;
    }
    return (first1 == last1) && (first2 != last2);
}

template <typename InputIterator1, typename InputIterator2>
bool equal_impl(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2,
    std::input_iterator_tag, std::input_iterator_tag)
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
bool equal_impl(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Comp comp,
    std::input_iterator_tag, std::input_iterator_tag)
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


template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare(
    InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2)
{
    return lexicographical_compare_impl(first1, last1, first2, last2,
                iterator_category(first1), iterator_category(first2));
}

template <typename InputIterator1, typename InputIterator2, typename Comp>
bool lexicographical_compare (
    InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Comp comp)
{
    return lexicographical_compare_impl(first1, last1, first2, last2, comp,
                iterator_category(first1), iterator_category(first2));
}

template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2)
{
    return equal_impl(first1, last1, first2, last2,
                iterator_category(first1), iterator_category(first2));
}

template <typename InputIterator1, typename InputIterator2, typename Comp>
bool equal(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Comp comp)
{
    return equal_impl(first1, last1, first2, last2, comp,
                iterator_category(first1), iterator_category(first2));
}


//Common operators overload:
template<typename IteratorF, typename IteratorS>
bool    operator_eq_impl(const IteratorF f, const IteratorS s,
    std::input_iterator_tag, std::input_iterator_tag)
{
    return f.base() == s.base();
}

template<typename IteratorF, typename IteratorS>
bool    operator_less_impl(const IteratorF f, const IteratorS s,
    std::input_iterator_tag, std::input_iterator_tag)
{
    return f.base() < s.base();
}

template<typename IteratorF, typename IteratorS>
bool    operator_less_eq_impl(const IteratorF f, const IteratorS s,
    std::input_iterator_tag, std::input_iterator_tag)
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
    return operator_less_eq_impl(
            f, s, iterator_category(f), iterator_category(s));
}

template<typename IteratorF, typename IteratorS>
bool    operator>=(const IteratorF f, const IteratorS s)
{
    return operator_less_eq_impl(
            s, f, iterator_category(f), iterator_category(s));
}

template<typename Iterator>
typename Iterator::iter_t
operator+(const typename Iterator::difference_type n, const Iterator &iter)
{
    return iter + n;
}

template<typename Iterator>
typename Iterator::iter_t
operator-(const typename Iterator::difference_type n, const Iterator &iter)
{
    return iter - n;
}


//Utils:
static const bool setVoid = true;

template<bool SetVoidType, typename T>
struct SetType {};

template<typename T>
struct SetType<true, T> {typedef void type;};

template<typename T>
struct SetType<false, T> {typedef T type;};


//IsSameIter:
template<typename Iterator, typename IteratorTag,
    bool IsIntegral = is_integral<Iterator>::value>
struct IsSameIter{};

template<typename Iterator, typename IteratorTag>
struct IsSameIter<Iterator, IteratorTag, false>
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<is_same<IteratorTag, iter_category>::value, Iterator>
    ::type  type;
};


//IsOutputIter:
template<typename Iterator, bool SetVoidType = false,
    bool IsIntegral = is_integral<Iterator>::value>
struct IsOutputIter{};

template<typename Iterator, bool SetVoidType>
struct IsOutputIter<Iterator, SetVoidType, false>
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::output_iterator_tag, iter_category>::value,
        typename SetType<SetVoidType, Iterator>::type>::type  type;
};

//IsRandomIter:
template<typename Iterator, bool SetVoidType = false,
    bool IsIntegral = is_integral<Iterator>::value>
struct IsRandomIter{};

template<typename Iterator, bool SetVoidType>
struct IsRandomIter<Iterator, SetVoidType, false>
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::random_access_iterator_tag, iter_category>::value,
        typename SetType<SetVoidType, Iterator>::type>::type  type;
};

//IsBiDirIter:
template<typename Iterator, bool SetVoidType = false,
    bool IsIntegral = is_integral<Iterator>::value>
struct IsBiDirIter{};

template<typename Iterator, bool SetVoidType>
struct IsBiDirIter<Iterator, SetVoidType, false>
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::bidirectional_iterator_tag, iter_category>::value
    || is_same<std::random_access_iterator_tag, iter_category>::value,
        typename SetType<SetVoidType, Iterator>::type>::type  type;
};

//IsForwardIter:
template<typename Iterator, bool SetVoidType = false,
    bool IsIntegral = is_integral<Iterator>::value>
struct IsForwardIter{};

template<typename Iterator, bool SetVoidType>
struct IsForwardIter<Iterator, SetVoidType, false>
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef
typename enable_if<
    is_same<std::forward_iterator_tag, iter_category>::value
    || is_same<std::bidirectional_iterator_tag, iter_category>::value
    || is_same<std::random_access_iterator_tag, iter_category>::value,
        typename SetType<SetVoidType, Iterator>::type>::type  type;
};

//IsInputIter:
template<typename Iterator, bool SetVoidType = false,
    bool IsIntegral = is_integral<Iterator>::value>
struct IsInputIter{};

template<typename Iterator, bool SetVoidType>
struct IsInputIter<Iterator, SetVoidType, false>
{
private:
typedef typename iterator_traits<Iterator>::iterator_category   iter_category;

public:
typedef typename enable_if<
    is_same<std::input_iterator_tag, iter_category>::value
    || is_same<std::forward_iterator_tag, iter_category>::value
    || is_same<std::bidirectional_iterator_tag, iter_category>::value
    || is_same<std::random_access_iterator_tag, iter_category>::value,
        typename SetType<SetVoidType, Iterator>::type>::type  type;
};

}
