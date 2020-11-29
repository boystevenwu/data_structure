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
    // item refers to the Object, left and right provide indexes to children
    struct Node
    {
        Object item;
        int left;
        int right;
        explicit Node(Object o, int index)
                : item{o}, left{2*index+1}, right{2*index+2} { }
    };

    // min heap array implemented
    std::vector<Node> queue;

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
    queue.push_back(Node(elem, queue.size()));
}


template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
    if (isEmpty()) {
        throw PriorityQueueEmptyException("The Queue is Empty");
    }
    else {
        return queue.at(0).item;
    }
}


template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
    if (isEmpty()) {
        throw PriorityQueueEmptyException("The Queue is Empty");
    }
    else {
        queue.erase(queue.begin());
    }
}


#endif 
