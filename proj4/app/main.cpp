#include <fstream>
#include <iostream>
#include "MyAVLTree.hpp"

int main()
{
    MyAVLTree<int, std::string> tree;
    tree.insert(10, "foo");
    tree.insert(3, "sna");
    tree.insert(5, "bar");
    tree.insert(12, "twelve");
    tree.insert(15, "fifteen");

    std::cout << tree.find(15) << " " << ( tree.size() == 5 ) << std::endl;

    return 0;
}

