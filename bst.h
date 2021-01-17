#pragma once

#include <iostream>
#include <algorithm>

template <typename T, typename Compare = std::less<T> >
class BSTree
{
public:
    BSTree() : root_(nullptr)
    {
    }

    ~BSTree() {}

    void insert(const T &t) 
    {
        if(!root_) {
            root_ = new BstNode(t);
            return;
        }

        BstNode *cur = root_;
        BstNode *parent = nullptr;
        while(cur)
        {
            if(compare_(t, cur->data_)) // <
            {
                parent = cur;
                cur = cur->left_;
            }
            else if (compare_(cur->data_, t))
            {
                parent = cur;
                cur = cur->right_;
            }
            else {
                // EQ and do nothing
                return;
            }
        }
        if(compare_(t, parent->data_))
        {
            parent->left_ = new BstNode(t);
        } else {
            parent->right_ = new BstNode(t);
        }
    }

    void remove(const T &t)
    {
        if(root_ == nullptr)
        {
            return;
        }
        BstNode *cur = root_, *parent = nullptr;
        BstNode *target = nullptr;
        while(cur)
        {
            if(compare_(t, cur->data_))
            {
                parent = cur;
                cur = cur->left_;
            } else if(compare_(cur->data_, t)) {
                parent = cur;
                cur = cur->right_;
            }
            else {
                // find target
                target = cur;
                break;
            }
        }
        if(!target){
            std::cout << "target not on the tree" << std::endl;
            return;
        }
        
        // COND_1: 没有任何孩子
        if(target->left_ == nullptr && target->right_ == nullptr) {
            if(parent == nullptr){

            } else {

            }
        }
        // COND_2: 有一个孩子
        // COND_3: 有2个孩子
    }

private:
    struct BstNode
    {
        T data_;
        BstNode *left_;
        BstNode *right_;
        BstNode(T data = T()) : data_(data), left_(nullptr), right_(nullptr) {}
    };

    // fields
    BstNode *root_;
    Compare compare_;
};