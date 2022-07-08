/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:41:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/07/08 21:25:14 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"
#include "pair.hpp"

namespace ft
{
const int BLACK = 0;
const int RED = 1;

template<typename Data>
struct RBTree_node
{
typedef RBTree_node<Data>   node_t;

    unsigned int    color: 1;
    node_t          *parent;
    node_t          *left;
    node_t          *right;
    Data            data;

    RBTree_node(void): color(BLACK), parent(NULL), left(NULL), right(NULL){}
    RBTree_node(int c, const Data &d, node_t *p = NULL, node_t *l = NULL,
                    node_t *r = NULL)
        : color(c), parent(p), left(l), right(r), data(d){}
    RBTree_node(const node_t &inst): left(NULL), right(NULL){*this = inst;}

    node_t  &operator=(const node_t &inst)
    {
        if (this == &inst)
            return *this;
        color = inst.color;
        parent = inst.parent;
        left = inst.left;
        right = inst.right;
        data = inst.data;
        return *this;
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
typename Key, typename Value = void*,
typename Allocator = std::allocator<RBTree_node<pair<Key, Value> > > >
class RBTree
{
public:
typedef pair<Key, Value>    Data;
typedef RBTree_node<Data>   node_t;

private:
    Allocator       alloc;
    node_t          *root;

private:
    node_t *findNode(const Key &key) const
    {
        node_t *res = root;
        while (res && res->data.first != key)
        {
            res = res->data.first > key ? res->left : res->right;
        }
        return res;
    }

    node_t *getParent(const Key &key) const
    {
        node_t *next = root;
        node_t *res = next;
        while (next)
        {
            res = next;
            next = next->data.first > key ? next->left : next->right;
        }
        return res;
    }

    node_t  *findNodeToRemove(const Key &key)
    {
        node_t *next;
        node_t *node = findNode(key);
        if (node == NULL)
            return node;
        if (node->left && node->right)
        {
            next = node->right;
            while (next->left)
            {
                next = next->left;
            }
            node->data = next->data;
            node = next;
        }
        return node;
    }

    void    leftRotate(node_t *parentNode, bool SC = true)
    {
        node_t  *right = parentNode->right;
        parentNode->right = right->left;
        right->left = parentNode;
        right->parent = parentNode->parent;
        parentNode->parent = right;
        if (SC)
        {
            parentNode->color++;
            right->color++;
        }
        if (right->parent)
        {
            if (right->parent->right == parentNode)
                right->parent->right = right;
            else if (right->parent->left == parentNode)
                right->parent->left = right;
        }
        if (parentNode == root)
        {
            root = right;
            root->color = BLACK;
        }
    }

    void    rightRotate(node_t *parentNode, bool SC = true)
    {
        node_t  *left = parentNode->left;
        parentNode->left = left->right;
        left->right = parentNode;
        left->parent = parentNode->parent;
        parentNode->parent = left;
        if (SC)
        {
            parentNode->color++;
            left->color++;
        }
        if (left->parent)
        {
            if (left->parent->left == parentNode)
                left->parent->left = left;
            else if (left->parent->right == parentNode)
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
            parentNode->left->color++;
        if (parentNode->right)
            parentNode->right->color++;
        if (parentNode != root)
            parentNode->color++;
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
            std::cout << "NOT BALANCED (SWAP_C): node color: " << parentNode->color
                << " node key: " << parentNode->data.first << std::endl;
            printBT("", this->root, false);
            swapColor(parentNode->parent);
            doBalancingAfterInsert(parentNode->parent->parent);
        }
        else
        {
            if (uncle_is_rigth)
            {
                if (parentNode->rightColor() == RED)
                {
                    std::cout << "NOT BALANCED (RIGHT_R_LR): node color: " << parentNode->color
                    << " node key: " << parentNode->data.first << std::endl;
                    printBT("", this->root, false);
                    leftRotate(parentNode, false);
                    rightRotate(parentNode->parent->parent);
                }
                else
                {
                    std::cout << "NOT BALANCED (RIGHT_R): node color: " << parentNode->color
                    << " node key: " << parentNode->data.first << std::endl;
                    printBT("", this->root, false);
                    rightRotate(parentNode->parent);
                }
            }
            else
            {
                if (parentNode->leftColor() == RED)
                {
                    std::cout << "NOT BALANCED (LEFT_R_RR): node color: " << parentNode->color
                    << " node key: " << parentNode->data.first << std::endl;
                    printBT("", this->root, false);
                    rightRotate(parentNode, false);
                    leftRotate(parentNode->parent->parent);
                }
                else
                {
                    std::cout << "NOT BALANCED (LEFT_R): node color: " << parentNode->color
                    << " node key: " << parentNode->data.first << std::endl;
                    printBT("", this->root, false);
                    leftRotate(parentNode->parent);
                }
            }
        }
    }

    void    doBalancingAfterRemove(node_t *node)
    {
        node_t *parent = node->parent;
        if (parent == NULL)
            return;
        if (parent->left == node && parent->right->color == RED)
        {
            leftRotate(parent);
        }
        else if (parent->right == node && parent->left->color == RED)
        {
            rightRotate(parent);
        }
        if (parent->left == node && parent->right->color == BLACK
            && parent->right->rightColor() == BLACK
            && parent->right->leftColor() == BLACK)
        {
            parent->right->color++;
            if (parent->color == RED)
            {
                parent->color++;
                return ;
            }
            doBalancingAfterRemove(parent);
        }
        else if (parent->right == node && parent->left->color == BLACK
            && parent->left->rightColor() == BLACK
            && parent->left->leftColor() == BLACK)
        {
            parent->left->color++;
            if (parent->color == RED)
            {
                parent->color++;
                return ;
            }
            doBalancingAfterRemove(parent);
        }

        if (parent->left == node && parent->right->color == BLACK
            && parent->right->rightColor() == RED
            && parent->right->leftColor() == BLACK)
        {
            rightRotate(parent->right);
        }
        else if (parent->right == node && parent->left->color == BLACK
            && parent->left->leftColor() == RED
            && parent->right->rightColor() == BLACK)
        {
            leftRotate(parent->left);
        }
        else if (parent->left == node && parent->right->color == BLACK
            && parent->right->rightColor() == RED)
        {
            leftRotate(parent);
            parent->parent->color = parent->color + 1;
            parent->parent->right->color = BLACK;
            parent->color = BLACK;
            return ;
        }
        else if (parent->right == node && parent->left->color == BLACK
            && parent->left->rightColor() == RED)
        {
            rightRotate(parent);
            parent->parent->color = parent->color + 1;
            parent->parent->left->color = BLACK;
            parent->color = BLACK;
            return ;
        }
    }

public:
    RBTree(void): alloc(Allocator()), root(NULL){}
    ~RBTree(void){clear();}

    void insert(const Data &data)
    {
        if (root == NULL)
        {
            root = alloc.allocate(1);
            alloc.construct(root, node_t(BLACK, data));
            std::cout << "BALANCED" << std::endl;
            printBT("", this->root, false);
            return ;
        }
        node_t *parent = getParent(data.first);
        if (parent->data.first == data.first)
        {
            parent->data.second = data.second;
            return ;
        }
        node_t *node = alloc.allocate(1);
        alloc.construct(node, node_t(RED, data));
        if (parent->data.first > data.first)
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
        std::cout << "BALANCED" << std::endl;
        printBT("", this->root, false);
    }

    void insert(const Key &key, const Value val = NULL)
    {
        insert(ft::make_pair(key, val));
    }

    void remove(const Key &key)
    {
        node_t *parent;
        node_t *node = findNodeToRemove(key);
        if (node == NULL)
            return ;
        parent = node->parent;
        if (parent == NULL)
        {
            if (node->left)
                root = node->left;
            else
                root = node->right;
        }
        else if (node->color == RED)
        {
            if (parent->left == node)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else if (node->color == BLACK)
        {
            if (node->left)
            {
                node->data = node->left->data;
                node = node->left;
            }
            else if (node->right)
            {
                node->data = node->right->data;
                node = node->right;
            }
            else
            {
                doBalancingAfterRemove(node);
                if (parent->left == node)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
        }
        alloc.destroy(node);
        alloc.deallocate(node, 1);
        printBT("", this->root, false);
    }

    void remove(const Data &data){remove(data.first);}

    Data *find(const Key &key) const
    {
        node_t *res = findNode(key);
        if (res)
            return &res->data;
        return NULL;
    }

    Data *find(const Data &data) const
    {
        return find(data.first);
    }

    void clear(void){}
};

template<typename Data>
void printBT(const std::string& prefix,
    const typename ft::RBTree_node<Data> *nodeV, bool isLeft)
{
    std::cout << prefix;
    std::cout << (!isLeft ? "├──" : "└──" );
    if (nodeV == NULL){
        std::cout <<"\033[0;36m"<< "nil" << "\033[0m"<<std::endl;
        return ;
    }
    // print the value of the node
    if (nodeV->color == 0)
        std::cout <<"\033[0;36m"<< nodeV->data.first<<"\033[0m"<<std::endl;
    else
        std::cout <<"\033[0;31m"<< nodeV->data.first << "\033[0m"<<std::endl;
    printBT( prefix + (!isLeft ? "│   " : "    "), nodeV->right, false);
    printBT( prefix + (!isLeft ? "│   " : "    "), nodeV->left, true);
}

}
