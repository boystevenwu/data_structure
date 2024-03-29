// If you really want to make a program for the app, be my guest.
// You may prefer to do so in /exp instead.
// Or better yet, use gtest to automate your own test cases!
#include "proj1.hpp"
#include <iostream>

int main()
{
    std::map<char, unsigned> map_temp;
    puzzleSolver("ABF", "CC", "GX", map_temp);

    for (auto& item : map_temp) {
        std::cout << item.first << item.second << " ";
    }

    return 0;
}
