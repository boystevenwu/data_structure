#ifndef __PROJ2_QUEUE_HPP
#define __PROJ2_QUEUE_HPP

#include "runtimeexcept.hpp"
#include <iostream>
#include <memory>

class QueueEmptyException : public RuntimeException 
{
public:
	QueueEmptyException(const std::string & err) : RuntimeException(err) {}
};


template<typename Object>
class LLQueue
{
private:
    struct Node
    {
        Object item;
        std::shared_ptr<Node> next;
        explicit Node(Object obj)
        {
            item = obj;
            next = nullptr;
        }
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> rear;

    size_t length;


public:
	LLQueue();

	// These should be "deep copies" -- copy the contents, not just a pointer to the front.
	LLQueue(const LLQueue & st);
	LLQueue & operator=(const LLQueue & st);
	~LLQueue()
	{
		// You do need to implement the destructor though.
	}

	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	// We have two front() for the same reason the Stack in lecture week 2 had two top() functions.
	// If you do not know why there are two, your FIRST step needs to be to review your notes from that lecture.
	Object & front();
	const Object & front() const;

	void enqueue(const Object & elem);

    // does not return anything.  Just removes.
	void dequeue();

    void print();
};

// Fill in the functions here.
template<typename Object>
LLQueue<Object>::LLQueue()
    : head{nullptr}, rear{nullptr}, length{0} {
}

template<typename Object>
LLQueue<Object>::LLQueue(const LLQueue & st)
    : head{nullptr}, rear{nullptr}, length{0} {
    auto current {st.head};

    while (current != nullptr) {
        enqueue(current->item);
        current = current->next;
    }
}

template<typename Object>
LLQueue<Object>& LLQueue<Object>::operator=(const LLQueue & st) {
    head = nullptr;
    rear = nullptr;
    length = 0;
    auto current {st.head};

    while (current != nullptr) {
        enqueue(current->item);
        current = current->next;
    }

    return *this;
}


template<typename Object>
size_t LLQueue<Object>::size() const noexcept{
    return length;
}

template<typename Object>
bool LLQueue<Object>::isEmpty() const noexcept {
    return length == 0;
}

template<typename Object>
void LLQueue<Object>::print() {
    auto current {head};

    while (current != nullptr) {
        std::cout << current->item << " | ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename Object>
void LLQueue<Object>::enqueue(const Object & elem) {
    auto temp = std::make_shared<Node>(elem);

    if (head == nullptr) { head = temp; }
    else { rear->next = temp; }

    rear = temp;
    length += 1;
}

template<typename Object>
void LLQueue<Object>::dequeue() {
    if (length == 0) {
        throw QueueEmptyException("The queue is empty");
    }

    head = head->next;
    length -= 1;
}

template<typename Object>
Object & LLQueue<Object>::front() {
    if (length == 0) {
        throw QueueEmptyException("The queue is empty");
    }

    return head->item;
}

template<typename Object>
const Object & LLQueue<Object>::front() const {
    if (length == 0) {
        throw QueueEmptyException("The queue is empty");
    }

    return head->item;
}

#endif 
