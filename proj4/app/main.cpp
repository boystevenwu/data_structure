#include <fstream>
#include <iostream>
#include "MyAVLTree.hpp"

int main()
{
    MyAVLTree<int, std::string> tree;
    tree.insert(5, "foo");
    tree.insert(3, "bar");
    tree.insert(10, "sna");
    tree.insert(12, "twelve");
    tree.insert(15, "fifteen");
//    tree.insert(1, "qi");
//    tree.insert(15, "15");
//    tree.insert(20, "20");


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

