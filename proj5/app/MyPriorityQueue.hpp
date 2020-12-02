#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include "runtimeexcept.hpp"
#include <vector>
#include <iostream>

class PriorityQueueEmptyException : public RuntimeException 
{
public:
	PriorityQueueEmptyException(const std::string & err) : RuntimeException(err) {}
};




template<typename Object>
class MyPriorityQueue
{
private:
    // min heap array implemented
    std::vector<Object> queue;

    void print();

public:

    MyPriorityQueue();
    ~MyPriorityQueue();


 	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	void insert(const Object & elem);


	// Note:  no non-const version of this one.  This is on purpose because
	// the interior contents should not be able to be modified due to the
	// heap property.  This isn't true of all priority queues but 
	// for this project, we will do this.
	// min and extractMin should throw PriorityQueueEmptyException if the queue is empty.
	const Object & min() const; 

	void extractMin(); 

};


template<typename Object>
MyPriorityQueue<Object>::MyPriorityQueue() = default;

template<typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue() = default;


template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
	return queue.size(); // stub
}

template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
	return queue.size() == 0; // stub
}


template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem) 
{
    queue.push_back(elem);
    int index = queue.size() - 1;

    // Mimic a recursive run to return index 0 and perform swapping
    while (index != 0) { // exit the loop if reaching the top
        int parent = (index-1)/2;

        if (queue[parent] > queue[index]) {
            std::swap(queue[parent], queue[index]);
        }
        print();
        index = parent;
    }
}


template<typename Object>
void MyPriorityQueue<Object>::print() {
    for (auto i : queue) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
    if (isEmpty()) {
        throw PriorityQueueEmptyException("The Queue is Empty");
    }

    return queue.at(0);
}


template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
    if (isEmpty()) {
        throw PriorityQueueEmptyException("The Queue is Empty");
    }

    queue[0] = queue.back();
    queue.pop_back();
    int index = 0;

    // Mimic an iterative run to reach the bottom and perform swapping
    while ((index*2)+1 < queue.size()) { // exit the loop if reaching the bottom
        int left = (index*2)+1, right = (index*2)+2;
        int child;

        if (right >= queue.size()) { child = left; }
        else { child = left<right ? left:right; }

        if (queue[child] < queue[index]) {
            std::swap(queue[child], queue[index]);
        }
        print();
        index = child;
    }
}


#endif 
