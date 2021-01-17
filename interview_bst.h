#ifndef __BYTEDANCE_BST_TREE_H__
#define __BYTEDANCE_BST_TREE_H__

#include <map>

template<typename PAIR>
struct Select1st {
    typename PAIR::first_type &
    operator()(PAIR &p) {
        return p.first;
    }

    const typename PAIR::first_type &
    operator()(const PAIR &p) {
        return p.first;
    }
};

template<typename _Key, typename _Ty, typename KCompare = std::less<_Key>>
class BSTree {
public:
    typedef _Key                                    key_type;
    typedef _Ty                                     mapped_type;
    typedef std::pair<const key_type, mapped_type>  value_type;
    typedef KCompare                                key_compare;
private:
    template<typename _Val>
    struct tree_node {
        typedef tree_node *tree_node_ptr;
        _Val _M_value_field;
        tree_node_ptr _M_parent;
        tree_node_ptr _M_left;
        tree_node_ptr _M_right;

        template<typename... Args>
        tree_node(Args && ... args) 
            : _M_value_field(std::forward<Args>(args)...)
        {}

        static tree_node_ptr min(tree_node_ptr x) {
            while(x->_M_left != 0) x=x->_M_left;
            return x;
        }

        static tree_node_ptr max(tree_node_ptr x) {
            while(x->_M_right != 0) x = x->_M_right;
            return x;
        }
    };

    template<typename _Val>
    struct tree_node_iterator{
        tree_node<_Val> *_M_node; 
        void increment() {
            if(_M_node->_M_right)
            {
                _M_node = _M_node->_M_right;
                while(_M_node->_M_left) 
                {
                    _M_node = _M_node->_M_left;
                }
            } else if(_M_node->_M_parent) {
               _M_node = _M_node->_M_parent;
            }
        }
        void decrement() {
            // fixme
        }
    };

    tree_node<value_type> *_M_root_ptr;
    std::size_t            _M_size;
public:
    BSTree(): _M_root_ptr(nullptr), _M_size(0){}

    int size() const {return _M_size;}

    void insert(const value_type &vt)
    {
        if(!_M_root_ptr) {
            _M_root_ptr =  new tree_node<value_type>(vt);
            _M_size++;
            return;
        }
        __insert(vt, _M_root_ptr);
    }

    void __insert(const value_type &vt, tree_node<value_type> *rt)
    {
        if(key_compare(rt->_M_value_field, vt.first))
        {
            __insert(vt, rt->_M_right);
        } else {
            if(key_compare(vt.first, rt->_M_value_field))
            {
                __insert(vt, rt->_M_left);
            } else {
                // EQ

            }
        }
    }
};

#endif