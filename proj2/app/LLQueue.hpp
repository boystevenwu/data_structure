#ifndef __PROJ2_QUEUE_HPP
#define __PROJ2_QUEUE_HPP

#include "runtimeexcept.hpp"

class QueueEmptyException : public RuntimeException 
{
public:
	QueueEmptyException(const std::string & err) : RuntimeException(err) {}
};


template<typename Object>
class LLQueue
{
private:
	// fill in private member data here

public:
	LLQueue();

//	These are copy constructors and  assignment operators. 
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
};

// TODO:  Fill in the functions here. 


#endif 
