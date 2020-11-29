#include "proj5.hpp"
#include "MyPriorityQueue.hpp"

int main()
{
    MyPriorityQueue<int> mpq;

    mpq.insert(5);
    mpq.insert(10);
    mpq.insert(15);

    std::cout << mpq.size() << " " << mpq.isEmpty() << std::endl;
    std::cout << mpq.min() << mpq.min() << std::endl;

    mpq.extractMin();
    std::cout << mpq.min() << mpq.min() << std::endl;

    return 0;
}
