#include "LLQueue.hpp"
#include <string>

int main()
{
    LLQueue<float> queue;

    std::cout << queue.size() << " " << queue.isEmpty() << std::endl;
    queue.print();

    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(1);

    std::cout << queue.size() << " " << queue.isEmpty() << std::endl;
    queue.print();

    queue.dequeue();
    queue.dequeue();

    std::cout << queue.size() << " " << queue.isEmpty() << std::endl;
    queue.print();

    std::cout << std::endl;

    LLQueue<std::string> squeue;

    std::cout << squeue.size() << " " << squeue.isEmpty() << std::endl;
    squeue.print();

    squeue.enqueue("nihao");
    squeue.enqueue("hen");
    squeue.enqueue("meili");

    auto ssqueue {squeue};

    std::cout << ssqueue.front() << " " << ssqueue.front() << std::endl;
    ssqueue.print();

    std::cout << squeue.front() << " " << squeue.front() << std::endl;
    squeue.print();

    squeue.dequeue();
    squeue.dequeue();

    std::cout << squeue.front() << " " << squeue.front() << std::endl;
    squeue.print();

    auto ueue {squeue};
    std::cout << ueue.front() << " " << ueue.front() << std::endl;
    ueue.print();

    std::cout << ssqueue.front() << " " << ssqueue.front() << std::endl;
    ssqueue.print();

    ssqueue = ueue;

    std::cout << ssqueue.front() << " " << ssqueue.front() << std::endl;
    ssqueue.print();

    return 0;
}
