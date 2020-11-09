#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

#include "proj3.hpp"
#include "Wordset.hpp"


int main()
{
    WordSet w;

    w.insert("abc");
    w.insert("hjkl");
    w.insert("what");
    w.print();
    std::cout << w.getCapacity() << " " << w.getCount() << std::endl;

    w.insert("yoyo");
    w.insert("sweet");
    w.insert("right");
    w.insert("ok");
    w.print();
    std::cout << w.getCapacity() << " " << w.getCount() << std::endl;

    std::cout << w.contains("right") << std::endl;
    std::cout << w.contains("rrgtt") << std::endl;
    std::cout << w.contains("ok") << std::endl;

    return 0;
}

