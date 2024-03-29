/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:41:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/07/18 16:59:29 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <functional>

#include "utils.hpp"
#include "iterators.hpp"
#include "pair.hpp"

namespace ft
{
const int BLACK = 0;
const int RED = 1;

template<typename Data, typename Allocator>
struct RBTree_node
{
typedef Data                            data_t;
typedef RBTree_node<Data, Allocator>    node_t;

    unsigned int    color: 1;
    node_t          *parent;
    node_t          *left;
    node_t          *right;
    data_t           data;

private:
    Allocator   alloc;

public:
    RBTree_node(void)
        : color(BLACK), parent(NULL), left(NULL), right(NULL),
            alloc(Allocator()){}
    RBTree_node(int c, const data_t &d, node_t *p = NULL, node_t *l = NULL,
                    node_t *r = NULL)
        : color(c), parent(p), left(l), right(r), data(d), alloc(Allocator()){}
    RBTree_node(const node_t &inst)
        : left(NULL), right(NULL), alloc(Allocator()){*this = inst;}

    node_t          &operator=(const node_t &inst)
    {
        if (this == &inst)
            return *this;
        color = inst.color;
        parent = inst.parent;
        left = inst.left;
        right = inst.right;
        alloc.destroy(&data);
        alloc.construct(&data, inst.data);
        return *this;
    }

    void            setData(const data_t &new_data)
    {
        if (this->data == new_data)
            return ;
        alloc.destroy(&data);
        alloc.construct(&data, new_data);
    }

    unsigned int    leftColor(void) const
    {
        if (left)
            return left->color;
        return BLACK;
    }

    unsigned int    rightColor(void) const
    {
        if (right)
            return right->color;
        return BLACK;
    }

};


template<
typename Data = pair<const int, void*>,
typename Compare = std::less<typename Data::first_type>,
typename DataAllocator = std::allocator<Data>,
typename Allocator = std::allocator<RBTree_node<Data, DataAllocator> > >
class RBTree
{
template<bool IsConst>
struct common_iterator;

public:
typedef Data                                            data_t;
typedef typename Data::first_type                       t_key;
typedef typename Data::second_type                      value_t;
typedef RBTree_node<Data, DataAllocator>                node_t;
typedef RBTree<Data, Compare, DataAllocator, Allocator> rbtree_t;
typedef Compare                                         comp_t;

typedef RBTree::common_iterator<NotConst>       iterator;
typedef RBTree::common_iterator<Const>          const_iterator;
typedef common_reverse_iterator<iterator>       reverse_iterator;
typedef common_reverse_iterator<const_iterator> const_reverse_iterator;

private:
    Allocator   alloc;
    comp_t      comp;
    node_t      *root;
    node_t      *min;
    node_t      *max;
    size_t      len;

private:
    void clear(node_t *node)
    {
        if (node == NULL)
            return ;
        clear(node->left);
        clear(node->right);
        alloc.destroy(node);
        alloc.deallocate(node, 1);
    }

    node_t *getParent(t_key &key, node_t *pos = NULL) const
    {
        node_t *next;
        node_t *res;

        if (max && more(key, max->data.first))
            return max;
        if (pos)
            next = pos;
        else
            next = root;
        res = next;
        while (next)
        {
            res = next;
            if (eq(next->data.first, key))
                break ;
            else
                next = more(next->data.first, key) ? next->left : next->right;
        }
        return res;
    }

    node_t  *getMin(void) const
    {
        node_t *res = root;
        while (res && res->left)
        {
            res = res->left;
        }
        return res;
    }

    node_t  *getMax(void) const
    {
        node_t *res = root;
        while (res && res->right)
        {
            res = res->right;
        }
        return res;
    }

    node_t  *findNodeToRemove(t_key &key)
    {
        node_t *next;

        node_t *node = findNode(key);
        if (node == NULL)
        {
            return node;
        }
        if (node->left && node->right)
        {
            next = node->right;
            while (next->left)
            {
                next = next->left;
            }
            node->setData(next->data);
            node = next;
        }
        return node;
    }

    void    leftRotate(node_t *parentNode, bool swap_c = true)
    {
        node_t  *right = parentNode->right;
        parentNode->right = right->left;
        if (parentNode->right)
            parentNode->right->parent = parentNode;
        right->left = parentNode;
        right->parent = parentNode->parent;
        parentNode->parent = right;
        if (swap_c)
        {
            parentNode->color++;
            right->color++;
        }
        if (right->parent)
        {
            if (right->parent->right == parentNode)
                right->parent->right = right;
            else
                right->parent->left = right;
        }
        if (parentNode == root)
        {
            root = right;
            root->color = BLACK;
        }
    }

    void    rightRotate(node_t *parentNode, bool swap_c = true)
    {
        node_t  *left = parentNode->left;
        parentNode->left = left->right;
        if (parentNode->left)
            parentNode->left->parent = parentNode;
        left->right = parentNode;
        left->parent = parentNode->parent;
        parentNode->parent = left;
        if (swap_c)
        {
            parentNode->color++;
            left->color++;
        }
        if (left->parent)
        {
            if (left->parent->left == parentNode)
                left->parent->left = left;
            else
                left->parent->right = left;
        }
        if (parentNode == root)
        {
            root = left;
            root->color = BLACK;
        }
    }

    void    swapColor(node_t *parentNode)
    {
        if (parentNode->left)
        {
            parentNode->left->color++;
        }
        if (parentNode->right)
        {
            parentNode->right->color++;
        }
        if (parentNode != root)
        {
            parentNode->color++;
        }
    }

    void    doBalancingAfterInsert(node_t *parentNode)
    {
        bool    uncle_is_rigth;
        int     uncle_color;

        if (parentNode == NULL || parentNode->parent == NULL)
        {
            return ;
        }

        if (parentNode->parent->left == parentNode)
        {
            uncle_is_rigth = true;
            uncle_color = parentNode->parent->rightColor();
        }
        else
        {
            uncle_is_rigth = false;
            uncle_color = parentNode->parent->leftColor();
        }

        if (uncle_color == RED)
        {
            swapColor(parentNode->parent);
            if (parentNode->parent->parent
                && parentNode->parent->parent->color == RED)
            {
                doBalancingAfterInsert(parentNode->parent->parent);
            }
        }
        else
        {
            if (uncle_is_rigth)
            {
                if (parentNode->rightColor() == RED)
                {
                    leftRotate(parentNode, false);
                    rightRotate(parentNode->parent->parent);
                }
                else
                {
                    rightRotate(parentNode->parent);
                }
            }
            else
            {
                if (parentNode->leftColor() == RED)
                {
                    rightRotate(parentNode, false);
                    leftRotate(parentNode->parent->parent);
                }
                else
                {
                    leftRotate(parentNode->parent);
                }
            }
        }
    }

    void    doBalancingAfterRemove(node_t *node, node_t *brother)
    {
        if (node == NULL)
            return ;

        if (node->rightColor() == RED)
        {
            leftRotate(node);
            brother = node->right;

        }
        else if (node->leftColor() == RED)
        {
            rightRotate(node);
            brother = node->left;
        }

        if (brother->leftColor() == BLACK && brother->rightColor() == BLACK)
        {
            brother->color = RED;
            if (node == root)
            {
                return ;
            }
            else if (node->color == RED)
            {
                node->color = BLACK;
                return ;
            }

            if (node->parent->left == node)
            {
                brother = node->parent->right;
            }
            else
            {
                brother = node->parent->left;
            }
            node = node->parent;
            doBalancingAfterRemove(node, brother);
            return ;
        }
        else if (node->left == brother
            && brother->leftColor() == BLACK && brother->rightColor() == RED)
        {
            leftRotate(brother);
            brother = brother->parent;
        }
        else if (node->right == brother
            && brother->leftColor() == RED && brother->rightColor() == BLACK)
        {
            rightRotate(brother);
            brother = brother->parent;
        }

        if (node->right == brother)
        {
            leftRotate(node, false);
            node->parent->color = node->color;
            node->parent->right->color = BLACK;
            node->color = BLACK;
        }
        else
        {
            rightRotate(node, false);
            node->parent->color = node->color;
            node->parent->left->color = BLACK;
            node->color = BLACK;
        }
    }

    bool    eq(t_key &f, t_key &s) const {return !comp(f, s) && !comp(s, f);}
    bool    more(t_key &f, t_key &s) const {return comp(s, f);}
    bool    less(t_key &f, t_key &s) const {return comp(f, s);}
    bool    more_eq(t_key &f, t_key &s) const {return more(f, s) || eq(f, s);}
    bool    less_eq(t_key &f, t_key &s) const {return less(f, s) || eq(f, s);}

    data_t  *getNodeValuePtr(node_t *node) const
    {
        if (node == NULL)
            return &max->data;
        return &node->data;
    }

    node_t  *increment_node(node_t *node) const
    {
        node_t *next;

        if (node == NULL || node == max)
            return NULL;

        if (node->right)
        {
            if (node->right->left)
            {
                next = node->right;
                while (next->left)
                {
                    next = next->left;
                }
                return next;
            }
            return node->right;
        }
        if (less(node->parent->data.first, node->data.first))
        {
            next = node->parent;
            while (less(next->data.first, node->data.first))
            {
                next = next->parent;
            }
            return next;
        }
        return node->parent;
    }

    node_t  *decrement_node(node_t *node) const
    {
        node_t *next;

        if (node == NULL)
            return max;
        else if (node == min)
            return NULL;

        if (node->left)
        {
            if (node->left->right)
            {
                next = node->left;
                while (next->right)
                {
                    next = next->right;
                }
                return next;
            }
            return node->left;
        }
        if (more(node->parent->data.first, node->data.first))
        {
            next = node->parent;
            while (more(next->data.first, node->data.first))
            {
                next = next->parent;
            }
            return next;
        }
        return node->parent;
    }

public:
    RBTree(void): alloc(Allocator()), comp(Compare()), root(NULL), min(NULL),
        max(NULL), len(0){}

    RBTree(const rbtree_t &inst): alloc(Allocator()), comp(Compare()),
        root(NULL), min(NULL), max(NULL), len(0){*this = inst;}

    ~RBTree(void){clear(root);}

    rbtree_t    &operator=(const rbtree_t &inst)
    {
        if (this == &inst)
            return *this;
        if (root)
            clear();
        copyTree(inst.root);
        return *this;
    }

    void        copyTree(const node_t *node)
    {
        if (node == NULL)
            return ;
        insert(node->data);
        copyTree(node->left);
        copyTree(node->right);

    }

    pair<iterator, bool>    insert(const data_t &data, node_t *parent = NULL)
    {
        if (root == NULL)
        {
            root = alloc.allocate(1);
            alloc.construct(root, node_t(BLACK, data));
            min = root;
            max = root;
            len++;
            return ft::make_pair<iterator, bool>(iterator(root, this), true);
        }
        parent = getParent(data.first, parent);
        if (eq(parent->data.first, data.first))
        {
            return ft::make_pair<iterator, bool>(iterator(parent, this), false);
        }
        node_t *node = alloc.allocate(1);
        alloc.construct(node, node_t(RED, data));
        if (more(parent->data.first, data.first))
        {
            parent->left = node;
            node->parent = parent;
        }
        else
        {
            parent->right = node;
            node->parent = parent;
        }
        if (parent->color == RED)
            doBalancingAfterInsert(parent);
        if (less(node->data.first, min->data.first))
        {
            min = node;
        }
        else if (more(node->data.first, max->data.first))
        {
            max = node;
        }
        len++;
        return ft::make_pair<iterator, bool>(iterator(node, this), true);
    }

    pair<iterator, bool>    insert(
        t_key &key, value_t val = NULL, node_t *pos = NULL)
    {
        return insert(ft::make_pair(key, val), pos);
    }

    size_t remove(t_key &key)
    {
        node_t *parent;
        node_t *node = findNodeToRemove(key);
        if (node == NULL)
            return 0;
        parent = node->parent;
        if (parent == NULL)
        {
            if (node->left)
            {
                root = node->left;
            }
            else
            {
                root = node->right;
            }
            if (root)
            {
                root->color = BLACK;
                root->parent = NULL;
            }
        }
        else if (node->color == RED)
        {
            if (parent->left == node)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        else if (node->color == BLACK)
        {
            if (node->left)
            {
                node->setData(node->left->data);
                parent = node;
                node = node->left;
                parent->left = NULL;
            }
            else if (node->right)
            {
                node->setData(node->right->data);
                parent = node;
                node = node->right;
                parent->right = NULL;
            }
            else
            {
                if (parent->left == node)
                {
                    parent->left = NULL;
                    doBalancingAfterRemove(node->parent, node->parent->right);
                }
                else
                {
                    parent->right = NULL;
                    doBalancingAfterRemove(node->parent, node->parent->left);
                }
            }
        }
        if (node == min)
        {
            min = getMin();
        }
        else if (node == max)
        {
            max = getMax();
        }
        len--;
        alloc.destroy(node);
        alloc.deallocate(node, 1);
        return 1;
    }

    size_t remove(const data_t &data){return remove(data.first);}

    size_t  size(void) const {return len;}

    size_t  max_size(void) const {return alloc.max_size();}

    node_t *findNode(t_key &key) const
    {
        node_t *res = root;
        while (res && !eq(res->data.first, key))
        {
            res = more(res->data.first, key) ? res->left : res->right;
        }
        return res;
    }

    data_t *find(t_key &key) const
    {
        node_t *res = findNode(key);
        if (res)
            return &res->data;
        return NULL;
    }

    data_t *find(const data_t &data) const
    {
        return find(data.first);
    }

    void    clear(void)
    {
        clear(root);
        root = min = max = NULL;
        len = 0;
    }

    void    swap(rbtree_t &rhs)
    {
        node_t  *tmp;
        size_t  tmp_len;

        tmp = root;
        root = rhs.root;
        rhs.root = tmp;
        tmp = min;
        min = rhs.min;
        rhs.min = tmp;
        tmp = max;
        max = rhs.max;
        rhs.max = tmp;
        tmp_len = len;
        len = rhs.len;
        rhs.len = tmp_len;
    }

    //Iterators:
    iterator                begin(void){return iterator(min, this);}
    const_iterator          begin(void) const {return const_iterator(min, this);}
    iterator                end(void) {return iterator(NULL, this);}
    const_iterator          end(void) const {return const_iterator(NULL, this);}
    reverse_iterator        rbegin(void){return reverse_iterator(end());}
    const_reverse_iterator  rbegin(void) const
    {
        return const_reverse_iterator(cend());
    }

    reverse_iterator        rend(void){return reverse_iterator(begin());}
    const_reverse_iterator  rend(void) const
    {
        return const_reverse_iterator(cbegin());
    }

    const_iterator          cbegin(void) const {return const_iterator(min, this);}

    const_iterator          cend(void) const {return const_iterator(NULL, this);}
    const_reverse_iterator  crbegin(void) const
    {
        return const_reverse_iterator(cend());
    }

    const_reverse_iterator  crend(void) const
    {
        return const_reverse_iterator(cbegin());
    }

    void    checkBalance(void) const
    {
        checkBalanceBT(root);
    }

    void    print(void)
    {
        printBT("", root, false);
    }

};

template<
typename Data, typename Compare, typename DataAllocator, typename Allocator>
template<bool IsConst>
struct ft::RBTree<Data, Compare, DataAllocator, Allocator>::common_iterator
    : public iterator_base<std::bidirectional_iterator_tag,
                typename conditional<IsConst,
                    typename conditional_t<is_same<
                        typename data_t::second_type, void*>::value,
                    data_t, typename data_t::first_type>::type,
                const typename conditional_t<is_same<
                        typename data_t::second_type, void*>::value,
                    data_t, typename data_t::first_type>::type>::type>
{
typedef
typename RBTree<Data, Compare, DataAllocator, Allocator>::rbtree_t  t_rbtree;

typedef
typename RBTree<Data, Compare, DataAllocator, Allocator>::node_t    t_node;

typedef
typename common_iterator::iterator_base::difference_type            diff_type;

typedef
typename conditional_t<IsConst, diff_type, const diff_type>::type   diff_t;

typedef
typename conditional_t<IsConst, data_t, const data_t>::type         t_data;

typedef
typename conditional_t<IsConst, iterator, const_iterator>::type     iter_t;

private:
    t_node          *node;
    const rbtree_t  *rbtree;

private:
    friend const rbtree_t  *baseTree(const iter_t &inst)
    {
        return inst.rbtree;
    }

    t_data  &asterisk_impl(t_data*) const
    {
        return *rbtree->getNodeValuePtr(node);
    }

    t_key  &asterisk_impl(t_key*) const
    {
        return rbtree->getNodeValuePtr(node)->first;
    }

    t_data  *arrow_impl(t_data*) const
    {
        return rbtree->getNodeValuePtr(node);
    }

    t_key  *arrow_impl(t_key*) const
    {
        return &rbtree->getNodeValuePtr(node)->first;
    }

public:
    common_iterator(void): node(NULL), rbtree(NULL){}
    common_iterator(t_node *_node, const rbtree_t *_rbtree)
        : node(_node), rbtree(_rbtree){}

    common_iterator(const iterator &inst){*this = inst;}
    ~common_iterator(void){}

    iter_t  &operator=(const iterator &inst)
    {
        node = inst.base();
        rbtree = baseTree(inst);
        return *this;
    }

    iter_t  &operator++(void)
    {
        node = rbtree->increment_node(node);
        return *this;
    }

    iter_t  operator++(int)
    {
        node_t *cur = node;
        node = rbtree->increment_node(node);
        return iter_t(cur, rbtree);
    }

    iter_t  &operator--(void)
    {
        node = rbtree->decrement_node(node);
        return *this;
    }

    iter_t  operator--(int)
    {
        node_t *cur = node;
        node = rbtree->decrement_node(node);
        return iter_t(cur, rbtree);
    }

    typename conditional_t<is_same<typename t_data::second_type, void*>::value,
    t_data, typename t_data::first_type>::type
    &operator*(void) const
    {
        typename conditional_t<
            is_same<typename t_data::second_type, void*>::value,
                t_data, typename t_data::first_type>::type  *val = NULL;
        return asterisk_impl(val);
    }

    typename conditional_t<is_same<typename t_data::second_type, void*>::value,
    t_data, typename t_data::first_type>::type
    *operator->(void) const
    {
        typename conditional_t<
            is_same<typename t_data::second_type, void*>::value,
                t_data, typename t_data::first_type>::type  *val = NULL;
        return arrow_impl(val);
    }

    t_node  *base(void) const
    {
        return node;
    }

    void    swap(iter_t &rhs)
    {
        t_node *_node = node;
        const rbtree_t *_rbtree = rbtree;
        node = rhs.node;
        rhs.node = _node;
        rbtree = rhs.rbtree;
        rhs.rbtree = _rbtree;
    }

};

//Comparee operators:
template<
typename Data, typename Compare, typename DataAllocator, typename Allocator>
bool    operator==(const ft::RBTree<Data, Compare, DataAllocator, Allocator> &f,
const ft::RBTree<Data, Compare, DataAllocator, Allocator> &s)
{
    return equal(f.begin(), f.end(), s.begin(), s.end());
}

template<
typename Data, typename Compare, typename DataAllocator, typename Allocator>
bool    operator!=(const ft::RBTree<Data, Compare, DataAllocator, Allocator> &f,
const ft::RBTree<Data, Compare, DataAllocator, Allocator> &s)
{
    return !(f == s);
}

template<
typename Data, typename Compare, typename DataAllocator, typename Allocator>
bool    operator<(const ft::RBTree<Data, Compare, DataAllocator, Allocator> &f,
const ft::RBTree<Data, Compare, DataAllocator, Allocator> &s)
{
    return ft::lexicographical_compare(f.begin(), f.end(), s.begin(), s.end());
}

template<
typename Data, typename Compare, typename DataAllocator, typename Allocator>
bool    operator<=(const ft::RBTree<Data, Compare, DataAllocator, Allocator> &f,
const ft::RBTree<Data, Compare, DataAllocator, Allocator> &s)
{
    return (f < s) || (f == s);
}

template<
typename Data, typename Compare, typename DataAllocator, typename Allocator>
bool    operator>(const ft::RBTree<Data, Compare, DataAllocator, Allocator> &f,
const ft::RBTree<Data, Compare, DataAllocator, Allocator> &s)
{
    return !(f < s) && (f != s);
}

template<
typename Data, typename Compare, typename DataAllocator, typename Allocator>
bool    operator>=(const ft::RBTree<Data, Compare, DataAllocator, Allocator> &f,
const ft::RBTree<Data, Compare, DataAllocator, Allocator> &s)
{
    return (f > s) || (f == s);
}

//std::swap:
template<
typename Data, typename Compare, typename DataAllocator, typename Allocator>
void    swap(ft::RBTree<Data, Compare, DataAllocator, Allocator> &f,
ft::RBTree<Data, Compare, DataAllocator, Allocator> &s)
{
    f.swap(s);
}

template<typename Data, typename DataAllocator>
void printBT(const std::string& prefix,
    const typename ft::RBTree_node<Data, DataAllocator> *nodeV, bool isLeft)
{
    std::cout << prefix;
    std::cout << (!isLeft ? "├──" : "└──" );
    if (nodeV == NULL){
        std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
        return ;
    }
    // print the value_t of the node
    if (nodeV->color == 0)
        std::cout <<"\033[0;36m"<< nodeV->data.first<<"\033[0m"<<std::endl;
    else
        std::cout <<"\033[0;31m"<< nodeV->data.first << "\033[0m"<<std::endl;
    printBT( prefix + (!isLeft ? "│   " : "    "), nodeV->right, false);
    printBT( prefix + (!isLeft ? "│   " : "    "), nodeV->left, true);
}

template<typename Data, typename DataAllocator>
void checkBalanceBT(const typename ft::RBTree_node<Data, DataAllocator> *node)
{
    if (node == NULL)
        return;
    if (node->color == RED
        && (node->leftColor() == RED || node->rightColor() == RED))
    {
        std::cout << "NOT BALANCED: doble red: node: "
            << node->data.first << std::endl;
        exit(1);
    }
    if (node->color == RED
        && ((node->left == NULL && node->right && node->right->color == BLACK)
            || (node->right == NULL && node->left && node->left->color == BLACK)))
    {
        std::cout << "NOT BALANCED: red and NULL and BLACK: node: "
            << node->data.first << std::endl;
        exit(1);
    }
    if (node->color == BLACK)
    {
        if (node->left == NULL && node->right && node->rightColor() == BLACK)
        {
            std::cout << "NOT BALANCED: black end NULL: node: "
            << node->data.first << std::endl;
            exit(1);
        }
        else if (node->right == NULL && node->left && node->leftColor() == BLACK)
        {
            std::cout << "NOT BALANCED: black end NULL: node: "
            << node->data.first << std::endl;
            exit(1);
        }
    }
    checkBalanceBT(node->left);
    checkBalanceBT(node->right);
}

}
