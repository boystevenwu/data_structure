#include "LLQueue.hpp"
#include "proj2.hpp"
#include <string>
#include <iostream>

int main()
{
    std::vector< std::vector<unsigned> > g1 = {
            {1, 2, 4}, {0,3}, {0,3}, {1,2,5, 7}, {0, 5, 6}, {3, 4}, {4, 7}, {3, 6},
    };

    std::vector<unsigned> pathLengths(8);
    std::vector<unsigned> numShortestPaths(8);

    countPaths(g1, 0, pathLengths, numShortestPaths);

    for (unsigned i : pathLengths) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (unsigned i : numShortestPaths) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
