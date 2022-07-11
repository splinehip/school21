/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:41:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/07/11 21:53:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <functional>

#include "utils.hpp"
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

    node_t  &operator=(const node_t &inst)
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

    void    setData(const data_t &new_data)
    {
        alloc.destroy(&data);
        alloc.construct(&data, new_data);
    }

    unsigned int    leftColor(void)
    {
        if (left)
            return left->color;
        return BLACK;
    }

    unsigned int    rightColor(void)
    {
        if (right)
            return right->color;
        return BLACK;
    }

};

template<
typename Data = pair<const int, void*>,
typename Compair = std::less<typename Data::first_type>,
typename DataAllocator = std::allocator<Data>,
typename Allocator = std::allocator<RBTree_node<Data, DataAllocator> > >
class RBTree
{
public:
typedef Data                                data_t;
typedef typename Data::first_type           t_key;
typedef typename Data::second_type          value_t;
typedef RBTree_node<Data, DataAllocator>    node_t;
typedef Compair                             comp_t;

private:
    Allocator   alloc;
    comp_t      comp;
    node_t      *root;
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

    node_t *findNode(t_key &key) const
    {
        node_t *res = root;
        while (res && !eq(res->data.first, key))
        {
            res = more(res->data.first, key) ? res->left : res->right;
        }
        return res;
    }

    node_t *getParent(t_key &key) const
    {
        node_t *next = root;
        node_t *res = next;
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

public:
    RBTree(void): alloc(Allocator()), comp(Compair()), root(NULL), len(0){}
    ~RBTree(void){clear(root);}

    void insert(const data_t &data)
    {
        if (root == NULL)
        {
            root = alloc.allocate(1);
            alloc.construct(root, node_t(BLACK, data));
            len++;
            return ;
        }
        node_t *parent = getParent(data.first);
        if (eq(parent->data.first, data.first))
        {
            parent->data.second = data.second;
            return ;
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
        len++;
    }

    void insert(t_key &key, value_t val = NULL)
    {
        insert(ft::make_pair(key, val));
    }

    void remove(t_key &key)
    {
        node_t *parent;
        node_t *node = findNodeToRemove(key);
        if (node == NULL)
            return ;
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
        alloc.destroy(node);
        alloc.deallocate(node, 1);
        len--;
    }

    void remove(const data_t &data){remove(data.first);}

    size_t  size(void) const {return len;}

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

    void clear(void){clear(root);}

    void checkBalance(node_t *node)
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
        checkBalance(node->left);
        checkBalance(node->right);
    }

    void    checkBalance(void)
    {
        checkBalance(root);
    }

    void    print(void)
    {
        printBT("", root, false);
    }
};

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

}
