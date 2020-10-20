// If you really want to make a program for the app, be my guest.
// You may prefer to do so in /exp instead.
// Or better yet, use gtest to automate your own test cases!
#include "proj1.hpp"
#include <iostream>

int main()
{
    std::map<char, unsigned> puzzle;
    std::cout << puzzleSolver("AB", "CDE", "FGH", puzzle) << std::endl;
    std::cout << puzzleSolver("UCIWGZ", "ALEXP", "MIKE", puzzle) << std::endl;
    std::cout << puzzleSolver("UCI", "ALEXA", "MIKE", puzzle) << std::endl;
    std::cout << puzzleSolver("ABCDE", "FGHIJ", "HJBCE", puzzle) << std::endl;

    return 0;
}
