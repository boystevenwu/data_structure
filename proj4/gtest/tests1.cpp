#include "gtest/gtest.h"
#include "MyAVLTree.hpp"
#include "proj4.hpp"
#include <string>
#include <sstream>
#include <vector>

namespace{


// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.

// The four tests marked "CheckPoint" are going to be run
// on your submission for the checkpoint code.
// This is worth one-sixth of your grade on the assignment
// and is due at the time marked "checkpoint"


// None of the "checkpoint" tests require you to have
// AVL functionality OR the counting of words.
// Implementing your tree as a plain binary search
// tree is more than enough to pass these tests.

// Of course, you are expected to implement AVL functionality
// for the full project.

// BE SURE TO FULLY TEST YOUR CODE.
// This means making sure your templating is not hard-coding for 
// a specific type, that every function is called somewhere in 
// your test cases, etc. 
// There will NOT be a project 2 style redo for this;  if your 
//  code does not compile, your score will be a zero. 


TEST(CheckPoint, CheckPoint_FindTheRoot)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");

	EXPECT_TRUE( tree.contains(5) );
}

TEST(CheckPoint, CheckPoint_FindOneHop)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(10, "bar");

	EXPECT_TRUE( tree.contains(10) );
}

TEST(CheckPoint, CheckPoint_FindTwoHops)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");

	EXPECT_TRUE( tree.contains(12) );
}



TEST(CheckPoint, CheckPoint_Add5)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	EXPECT_TRUE( tree.size() == 5 );
}



TEST(PostCheckPoint, InOrderTraversal)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	std::vector<int> trav = tree.inOrder();
	std::vector<int> expected = {3, 5, 10, 12, 15};
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, PreOrderTraversal_rr)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	std::vector<int> trav = tree.preOrder();
	// std::vector<int> expected = {5, 3, 10, 12, 15}; // normal BST
	std::vector<int> expected = {5, 3, 12, 10, 15}; // AVL
	EXPECT_TRUE( trav == expected );
}


TEST(PostCheckPoint, PreOrderTraversal_ll)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(12, "foo");
	tree.insert(10, "sna");
	tree.insert(15, "bar");
	tree.insert(5, "twelve");
	tree.insert(3, "fifteen");

	std::vector<int> trav = tree.preOrder();
	std::vector<int> expected = {12, 5, 3, 10, 15}; // AVL
	EXPECT_TRUE( trav == expected );
}


TEST(PostCheckPoint, PreOrderTraversal_lr_test)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(20, "foo");
	tree.insert(10, "sna");
	tree.insert(30, "bar");
	tree.insert(8, "twelve");
	tree.insert(13, "fifteen");
	tree.insert(11, "ele");

	std::vector<int> trav = tree.preOrder();
	std::vector<int> expected = {13, 10, 8, 11, 20, 30}; // AVL
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, PreOrderTraversal_lr)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(20, "foo");
	tree.insert(10, "sna");
	tree.insert(30, "bar");
	tree.insert(8, "twelve");
	tree.insert(13, "fifteen");
	tree.insert(11, "ele");
	tree.insert(15, "fif");

	std::vector<int> trav = tree.preOrder();
	std::vector<int> expected = {13, 10, 8, 11, 20, 15, 30}; // AVL
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, PreOrderTraversal_rl)
{
	MyAVLTree<int, std::string> tree;
    	tree.insert(10, "foo");
	tree.insert(5, "sna");
	tree.insert(20, "bar");
	tree.insert(15, "twelve");
	tree.insert(30, "fifteen");
	tree.insert(13, "ele");
    	tree.insert(17, "sev");

	std::vector<int> trav = tree.preOrder();
	std::vector<int> expected = {15, 10, 5, 13, 20, 17, 30}; // AVL
	EXPECT_TRUE( trav == expected );
}



TEST(PostCheckPoint, PostOrderTraversal)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	std::vector<int> trav = tree.postOrder();
	std::vector<int> expected = {3, 10, 15, 12, 5};
	EXPECT_TRUE( trav == expected );
}
	
TEST(PostCheckPoint, PostOrder_test2)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(7, "foo");
	tree.insert(6, "sna");
	tree.insert(5, "bar");
	tree.insert(4, "twelve");
	tree.insert(3, "fifteen");
	tree.insert(2, "twelve");
	tree.insert(1, "fifteen");

	std::vector<int> trav = tree.postOrder();
	std::vector<int> expected = {1, 3, 2, 5, 7, 6, 4}; // AVL
	EXPECT_TRUE( trav == expected );
}
	
	
TEST(PostCheckPoint, JackSparrow)
{
	std::string quote = "I'm dishonest, and a dishonest man you can ";
	quote += "always trust to be dishonest. Honestly. It's the honest ";
	quote += "ones you want to watch out for, because you can never ";
	quote += "predict when they're going to do something incredibly... stupid.";

	std::istringstream stream( quote );

	MyAVLTree<std::string, unsigned> tree;

	countWords(stream, tree);
	EXPECT_TRUE(tree.find("dishonest") == 3);
}

TEST(PostCheckPoint, JackSparrow_test2)
{
	std::string quote = "I'm dishonest, and a dishonest man you can ";
	quote += "always trust to be dishonest. Honestly. It's the honest ";
	quote += "ones you want to watch out for, because you can never ";
	quote += "predict when they're going to do something incredibly... stupid.";

	std::istringstream stream( quote );

	MyAVLTree<std::string, unsigned> tree;

	countWords(stream, tree);
	EXPECT_TRUE(tree.find("its") == 1);
}
	
TEST(PostCheckPoint, HameltOpen_good)
{
	MyAVLTree<std::string, unsigned> tree; 
	std::fstream fs;
	fs.open("/home/ics46/projects/proj4/gtest/hamletopen.txt");
	countWords(fs, tree);
	EXPECT_TRUE(tree.find("good") == 4);
}	

TEST(PostCheckPoint, HameltOpen_you)
{
	MyAVLTree<std::string, unsigned> tree; 
	std::fstream fs;
	fs.open("/home/ics46/projects/proj4/gtest/hamletopen.txt");
	countWords(fs, tree);
	EXPECT_TRUE(tree.find("you") == 6);
}

TEST(PostCheckPoint, Hamlet_1)
{
     MyAVLTree<std::string, unsigned> tree; 
     std::fstream fs;
     fs.open("/home/ics46/projects/proj4/gtest/hamletact1.txt");
     countWords(fs, tree);
     EXPECT_TRUE(tree.find("lord") == 60);
     EXPECT_TRUE(tree.find("hamlet") == 103);
     EXPECT_TRUE(tree.find("speak") == 27);
     EXPECT_TRUE(tree.find("me") == 47);
     EXPECT_TRUE(tree.find("and") == 229);
     EXPECT_TRUE(tree.find("good") == 20);
     EXPECT_TRUE(tree.find("cast") == 3);
     EXPECT_TRUE(tree.find("all") == 36);
}

TEST(PostCheckPoint, Hamlet_2)
{
     MyAVLTree<std::string, unsigned> tree; 
     std::fstream fs;
     fs.open("/home/ics46/projects/proj4/gtest/hamletopen.txt");
     countWords(fs, tree);
     EXPECT_TRUE(tree.find("francisco") == 10);
     EXPECT_TRUE(tree.find("holla") == 1);
     EXPECT_TRUE(tree.find("farewell") == 1);

     EXPECT_TRUE(tree.find("a") == 3);
     EXPECT_TRUE(tree.find("bernardo") == 16);
     EXPECT_TRUE(tree.find("most") == 1);
     EXPECT_TRUE(tree.find("night") == 5);
     EXPECT_TRUE(tree.find("carefully") == 1);
}

}
