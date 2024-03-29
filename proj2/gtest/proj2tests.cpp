#include "gtest/gtest.h"
#include "LLQueue.hpp"
#include "proj2.hpp"


namespace{


// NOTE:  these are not intended as exhaustive tests.
	// This should get you started testing.
	// You should make your own additional tests for both queue
	// and for the social network question.
	// VERY IMPORTANT:  if your LLQueue is not templated, or if 
	//		it is not linked-list based, your score for this project
	//		will be zero.  Be sure your LLQueue compiles and runs 
	// 		with non-numeric data types. 

TEST(QueueTest, QueueTest1)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	a.enqueue(1);
	EXPECT_TRUE( a.front() == 5 );

    auto b = a;
    EXPECT_TRUE( b.front() == 5 );

    auto c {b};
    EXPECT_TRUE( c.front() == 5 );
}

TEST(QueueTest, QueueTest2)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
    a.dequeue();
    
	EXPECT_TRUE( a.front() == 3 );
}


TEST(QueueTest, QueueTest3)
{
	LLQueue<std::string> a;
	a.enqueue("a");
	a.enqueue("b");
	a.enqueue("c");
	a.enqueue("d");
	a.enqueue("f");

    auto b = a;

	a.dequeue();
	EXPECT_TRUE( a.front() == "b" );

	EXPECT_TRUE( b.front() == "a" );
    EXPECT_TRUE( b.size() - 1 == a.size() );

    while (b.size() > 0) {
        b.dequeue();
    }
    EXPECT_TRUE( b.size() == 0);
}

TEST(QueueTest, QueueTest4)
{
	LLQueue<std::string> a;
	a.enqueue("a");
	a.enqueue("b");
	a.enqueue("c");
	a.enqueue("d");
	a.enqueue("f");

    auto b = a;

	a.dequeue();
    EXPECT_TRUE( b.size() - 1 == a.size() );

    while (b.size() > 0) {
        b.dequeue();
    }
    EXPECT_TRUE( b.size() == 0 );
    
    auto c {b};
    EXPECT_TRUE( c.size() == 0 );

    c = a;
    EXPECT_TRUE( c.size() == a.size() );
    EXPECT_TRUE( c.front() == "b" );
}

TEST(GraphTest, GraphTest1)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1,2}, {0,3}, {0,3}, {1,2,4}, {3, 5}, {4}
	};
	std::vector<unsigned> pathLengths(6);
	std::vector<unsigned> numShortestPaths(6);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2, 3, 4};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2, 2, 2};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}


TEST(GraphTest, GraphTest2)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3}, {0,3}, {1,2,5}, {0, 5}, {3, 4}
	};
	
	std::vector<unsigned> pathLengths(6);
	std::vector<unsigned> numShortestPaths(6);
	
	countPaths(g1, 5, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {2, 2, 2, 1, 1, 0};
	std::vector<unsigned> expNumSP = {1, 1, 1, 1, 1, 1};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);
}

TEST(GraphTest, GraphTest3)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3}, {0,3}, {1,2,5, 7}, {0, 5, 6}, {3, 4}, {4, 7}, {3, 6},
	};
	
	std::vector<unsigned> pathLengths(8);
	std::vector<unsigned> numShortestPaths(8);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2, 1, 2, 2, 3};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2, 1, 1, 1, 3};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}

TEST(GraphTest, GraphTest4)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3,5}, {0,3,5}, {1,2,4}, {0,3,5}, {1,2,4}
	};
	
	std::vector<unsigned> pathLengths(6);
	std::vector<unsigned> numShortestPaths(6);
	
	countPaths(g1, 2, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {1, 2, 0, 1, 2, 1};
	std::vector<unsigned> expNumSP = {1, 3, 1, 1, 3, 1};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);
}

}
