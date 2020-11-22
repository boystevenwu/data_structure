// This header file contains declarations and implementations of AVL Tree
// Using template and linked list to maintain the data structure

#ifndef __PROJ_FOUR_AVL_HPP
#define __PROJ_FOUR_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};


// Class declaration
template<typename Key, typename Value>
class MyAVLTree
{
private:
    // Linked list item
    struct Node
    {
        Key key;
        Value value;
        int height;
        Node* left;
        Node* right;
        explicit Node(Key k, Value v)
            : key{k}, value{v}, height{0}, left{nullptr}, right{nullptr} { }
    };

    Node*& compass(Node* current, const Key &k) const;
    void insertHelp(Node*& current, const Key &k, const Value &v);

    void rotate(Node*& current);

    Node* root; 
	
	//Add Here -oh
	void inOrderHelp(Node* current, std::vector<Key>& foo) const;
	void preOrderHelp(Node* current, std::vector<Key>& foo) const;
	void postOrderHelp(Node* current, std::vector<Key>& foo) const;

    // Delete the leaves by traversal
	void deleteHelp(Node* current) {
        if (current == nullptr) { return; }

        deleteHelp(current -> left);
        deleteHelp(current -> right);

        delete current;
	}

    size_t length;

public:
	MyAVLTree();

	// In general, a copy constructor and assignment operator
	// are good things to have.
	// For this quarter, I am not requiring these. 
	//	MyAVLTree(const MyAVLTree & st);
	//	MyAVLTree & operator=(const MyAVLTree & st);


	// The destructor is, however, required. 
	~MyAVLTree()
	{
        deleteHelp(root);
	}

	// size() returns the number of distinct keys in the tree.
	size_t size() const noexcept;

	// isEmpty() returns true if and only if the tree has no values in it. 
	bool isEmpty() const noexcept;

	// contains() returns true if and only if there
	// is a (key, value) pair in the tree
	// that has the given key as its key.
	bool contains(const Key & k) const; 

	// find returns the value associated with the given key
	// If !contains(k), this will throw an ElementNotFoundException
	// There needs to be a version for const and non-const MyAVLTrees.
	Value & find(const Key & k);
	const Value & find(const Key & k) const;

	// Inserts the given key-value pair into 
	// the tree and performs the AVL re-balance
	// operation, as described in lecture. 
	// If the key already exists in the tree, 
	// you may do as you please (no test cases in
	// the grading script will deal with this situation)
	void insert(const Key & k, const Value & v);

	// in general, a "remove" function would be here
	// It's a little trickier with an AVL tree
	// and I am not requiring it for this quarter's ICS 46.
	// You should still read about the remove operation
	// in your textbook. 

	// The following three functions all return
	// the set of keys in the tree as a standard vector.
	// Each returns them in a different order.
	std::vector<Key> inOrder() const;
	std::vector<Key> preOrder() const;
	std::vector<Key> postOrder() const;

};


// Constructor of Tree
template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree() : root{nullptr}, length{0}
{

}

// Return the number of leaves in the tree
template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept
{
	return length;
}

// Return the bool indicator whether the tree is empty
template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept
{
    return length == 0;
}

// Navigate the key when searching its supposed location
template<typename Key, typename Value>
typename MyAVLTree<Key, Value>::Node*& MyAVLTree<Key, Value>::compass(Node* current, const Key &k) const
{
    return k < current->key ? current->left:current->right;
}

/**
 * Implement the rotation mechanism per instructions
 * compare the subtree heights by their stored info
 * and rotate the branches with corresponding actions
 */
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::rotate(Node*& current) {
    int left, right;

    if (current->left == nullptr) { left = -1; }
    else { left = current->left->height; }
    if (current->right == nullptr) { right = -1; }
    else { right = current->right->height; }

    auto temp = current;
    auto temp2 = current;
    int scenario = 0;
    if (left - right > 1) {
        if (current->left->right == nullptr) { scenario = 1; }
        else if (current->left->left == nullptr) { scenario = 3; }
        else if (current->left->left->height > current->left->right->height) { scenario = 1; }
        else if (current->left->left->height < current->left->right->height) { scenario = 3; }
    }
    else if (right - left > 1) {
        if (current->right->left == nullptr) { scenario = 2; }
        else if (current->right->right == nullptr) { scenario = 4; }
        else if (current->right->right->height > current->right->left->height) { scenario = 2; }
        else if (current->right->right->height < current->right->left->height) { scenario = 4; }
    }

    switch (scenario) {
        default:
            break;
        case 1:
            current = current->left;
            temp->left = current->right;
            temp->height = right + 1;
            current->right = temp;
            break;
        case 2:
            current = current->right;
            temp->right = current->left;
            temp->height = left + 1;
            current->left = temp;
            break;
        case 3:
            current = current->left;
            current = current->right;
            temp = temp->left;
            temp->right = current->left;
            temp2->left = current->right;
            current->left = temp;
            temp2->height = right + 1;
            current->right = temp2;
            break;
        case 4:
            current = current->right;
            current = current->left;
            temp = temp->right;
            temp->left = current->right;
            temp2->right = current->left;
            current->right = temp;
            temp2->height = left + 1;
            current->left = temp2;
            break;
    }
}

// Insert a key-value pair in the tree, track heights of leaves in the branch
// Call rotate after insertion to check the balance
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insertHelp(Node*& current, const Key &k, const Value &v)
{
    if (current == nullptr) {
        current = new Node(k,v);
    }
    else {
        insertHelp(compass(current, k), k, v);
        current->height = compass(current, k)->height + 1;
        rotate(current);
    }
}

// Call inserHelp() to insert items and increase the length afterwards
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key & k, const Value & v)
{
    insertHelp(root, k, v);

    length ++;
}

// check if a key exists in the tree by traversal
template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::contains(const Key &k) const
{
    auto current = root;

	while (current != nullptr) {
        if (current->key == k) { return true; }
	    else { current = compass(current, k); }
	}

	return false;
}

/**
 * Return the value of a key
 * Throw exception if not found
 * 
 * @return Value
 */
template<typename Key, typename Value>
Value & MyAVLTree<Key, Value>::find(const Key & k)
{
    auto current = root;

    while (current != nullptr) {
        if (current->key == k) { return current->value; }
        else { current = compass(current, k); }
    }

    throw ElementNotFoundException("Cannot find key");
}

/**
 * Return the value of a key
 * Throw exception if not found
 * 
 * @return Value
 */
template<typename Key, typename Value>
const Value & MyAVLTree<Key, Value>::find(const Key & k) const
{
    auto current = root;

    while (current != nullptr) {
        if (current->key == k) { return current->value; }
        else { current = compass(current, k); }
    }

    throw ElementNotFoundException("Cannot find key");
}

// Below 2 traverse the tree and return keys in a in order fashion
// @return vector
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::inOrderHelp(Node* current, std::vector<Key>& foo) const
{
	if (current == nullptr) { return; }

	inOrderHelp(current -> left, foo);
	foo.push_back(current -> key);
	inOrderHelp(current -> right, foo);
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrder() const
{
	std::vector<Key> foo;
	inOrderHelp(root, foo);
	return foo;
}

// Below 2 traverse the tree and return keys in a pre order fashion
// @return vector
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::preOrderHelp(Node* current, std::vector<Key>& foo) const
{
	if (current == nullptr) { return; }

	foo.push_back(current -> key);
	preOrderHelp(current -> left, foo);
	preOrderHelp(current -> right, foo);
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::preOrder() const
{
	std::vector<Key> foo;
	preOrderHelp(root, foo);
	return foo;
}

// Below 2 traverse the tree and return keys in a post order fashion
// @return vector
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::postOrderHelp(Node* current, std::vector<Key>& foo) const
{
	if (current == nullptr) { return; }

	postOrderHelp(current -> left, foo);
	postOrderHelp(current -> right, foo);
	foo.push_back(current -> key);
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrder() const
{
	std::vector<Key> foo;
	postOrderHelp(root, foo);
	return foo; 
}


#endif
