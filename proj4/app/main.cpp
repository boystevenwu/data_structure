#include <fstream>
#include <iostream>
#include "MyAVLTree.hpp"

int main()
{
    MyAVLTree<int, std::string> tree;
    tree.insert(10, "foo");
    tree.insert(3, "bar");
    tree.insert(12, "sna");
    tree.insert(1, "twelve");
    tree.insert(5, "fifteen");
    tree.insert(7, "qi");
    tree.insert(2, "15");
//    tree.insert(20, "20");
//    tree.insert(10, "20");
//    tree.insert(15, "20");


//    std::cout << tree.find(15) << " " << ( tree.size() == 5 ) << std::endl;

    auto v{tree.inOrder()};
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto w{tree.preOrder()};
    for (auto i : w) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto x{tree.postOrder()};
    for (auto i : x) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

