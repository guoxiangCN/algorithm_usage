#include "interview_bst.h"
#include <iostream>

int main(int argc, char **argv)
{
    BSTree<std::string, int> map;
    map.insert(std::pair<std::string,int>("java", 123));
    std::cout << map.size() << std::endl;
    return 0;
}