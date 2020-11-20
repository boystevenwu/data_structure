#ifndef __PROJ_FOUR_AVL_HPP
#define __PROJ_FOUR_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>
#include <iostream>

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};


template<typename Key, typename Value>
class MyAVLTree
{
private:
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


template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree() : root{nullptr}, length{0}
{

}

template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept
{
	return length;
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept
{
    return length == 0;
}

template<typename Key, typename Value>
typename MyAVLTree<Key, Value>::Node*& MyAVLTree<Key, Value>::compass(Node* current, const Key &k) const
{
    return k < current->key ? current->left:current->right;
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::rotate(Node*& current) {
    int left, right;

    if (current->left == nullptr) { left = -1; }
    else { left = current->left->height; }
    if (current->right == nullptr) { right = -1; }
    else { right = current->right->height; }

    std::cout << current->key << std::endl;
    auto temp = current;
    int scenario = 0;
    if (left - right > 1) {
        if (current->left->right == nullptr) { scenario = 1; }
//        else if (current->left->left == nullptr) { scenario = 3; }
        else if (current->left->left->height > current->left->right->height) { scenario = 1; }
//        else if (current->left->left < current->left->right) { scenario = 3; }
    }
    else if (right - left > 1) {
        if (current->right->left == nullptr) { scenario = 2; }
        else if (current->right->right->height > current->right->left->height) { scenario = 2; }
    }

    switch (scenario) {
        default:
            break;
        case 1:
            current = current->left;
            temp->left = current->right;
            temp->height = right + 1;
            current->right = temp;
            std::cout << scenario << " GO" << std::endl;
            break;
        case 2:
            current = current->right;
            temp->right = current->left;
            temp->height = left + 1;
            current->left = temp;
            std::cout << scenario << " GO" << std::endl;
            break;
    }
}

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

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key & k, const Value & v)
{
    insertHelp(root, k, v);

    length ++;
}

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
