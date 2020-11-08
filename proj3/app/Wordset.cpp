#include "Wordset.hpp"
#include <iostream>
#include <cmath>

const int BASE_TO_USE = 41; 
const double LOAD_LIMIT = 0.27;


// returns s, as a number in the given base, mod the given modulus
int hashFunction(const std::string& item, int base, int mod)
{
    double result = 0;
    unsigned length = item.length() - 1;

    for (int i = 0; i <= length; ++i) {
        result += item[length-i] * pow(base, i);
    }
    return int(result);
}


WordSet::WordSet() : level { 0 }, count{ 0 }, capacity{ SIZES[level] }, hash_table{ new Node[capacity] } {

}

WordSet::~WordSet() = default;

void WordSet::print() const {
    for (int i = 0; i < capacity; ++i) {
        std::cout << hash_table[i].item << " | ";
    }
    std::cout << std::endl;
}

std::string WordSet::get(int hash) const {
    return hash_table[hash % capacity].item;
}

void WordSet::add(const std::string& s) {
    int hash {hashFunction(s, BASE_TO_USE, capacity)};
    int i {0};

    while (true) {
        hash += i * i;
        std::cout << hash % capacity << " ";
        if (get(hash).empty()) {
            std::cout << std::endl;
            break;
        }
        else {
            hash -= i * i;
            i ++;
        }
    }


    hash_table[hash % capacity] = Node(s, i);
    count ++;
}

void WordSet::insert(const std::string& s)
{
    add(s);
}


bool WordSet::contains(const std::string& s) const
{
    int hash {hashFunction(s, BASE_TO_USE, capacity)};
    int i {0};

    while (true) {
        hash += i * i;

        if (get(hash) == s) {
            return true;
        }
        else if (i == count) {
            return false;
        }

        hash -= i * i;
        i ++;
    }
}

// return how many distinct strings are in the set
int WordSet::getCount() const
{
	return count;
}

// return how large the underlying array is.
int WordSet::getCapacity() const
{
	return capacity;
}
