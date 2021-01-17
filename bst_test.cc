#include "bst.h"

int main(int argc, char **argv)
{
    BSTree<int> tree;

    tree.insert(6);
    tree.insert(4);
    tree.insert(99);

    tree.remove(222);
    tree.remove(4);
    tree.remove(111);
    return 0;
}