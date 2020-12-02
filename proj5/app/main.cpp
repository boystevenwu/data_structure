#include "proj5.hpp"
#include "MyPriorityQueue.hpp"

int main()
{
    MyPriorityQueue<int> mpq;

    mpq.insert(10);
    mpq.insert(9);
    mpq.insert(8);
    mpq.insert(7);
    mpq.insert(6);
    mpq.insert(5);
    mpq.insert(5);
    mpq.insert(5);
    mpq.insert(5);
    mpq.insert(5);

//    std::cout << mpq.size() << " " << mpq.isEmpty() << std::endl;
//    std::cout << mpq.min() << mpq.min() << std::endl;

    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;
    return 0;
}
