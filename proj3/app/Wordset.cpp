#include "Wordset.hpp"
#include <iostream>
#include <cmath>

const int BASE_TO_USE = 41; 
const double LOAD_LIMIT = 0.27;


// returns s, as a number in the given base, mod the given modulus
int hashFunction(const std::string& item, int base, int mod)
{
    int result = 0;
    int length = item.length() - 1;

    for (int i = 0; i <= length; ++i) {
        result += fmod((item[length-i]-97) * pow(base, i), mod);
    }

    return fmod(result, mod);
}


WordSet::WordSet() 
    : level { 0 }, count{ 0 }, capacity{ SIZES[level] }, hash_table{ new Node[capacity] } {

}

WordSet::~WordSet() {
    delete[] hash_table;
}

void WordSet::print() const {
    for (int i = 0; i < capacity; ++i) {
        std::cout << hash_table[i].item << " | ";
    }
    std::cout << std::endl;
}

std::string WordSet::get(int hash) const {
    return hash_table[hash].item;
}

void WordSet::add(const std::string& s) {
    int hash {hashFunction(s, BASE_TO_USE, capacity)};
    int i {0};

    while (true) {
        auto temp {hash};
        hash += fmod(i * i, capacity);
        hash = fmod(hash, capacity);

        if (get(hash).empty()) {
            break;
        }
        hash = temp;
        i ++;
    }

    hash_table[hash] = Node(s, i);
    count ++;
}

void WordSet::insert(const std::string& s)
{
    add(s);

    if (count > LOAD_LIMIT * capacity) {
        Node* temp = new Node[capacity];
        for (int i = 0; i < capacity; ++i) {
            temp[i] = hash_table[i];
        }

        level += 1;
        count = 0;
        capacity = SIZES[level];

        delete[] hash_table;
        hash_table = new Node[capacity];

        for (int i = 0; i < SIZES[level-1]; ++i) {
            if (!temp[i].item.empty()) {
                add(temp[i].item);
            }
        }

        delete[] temp;
    }
}


bool WordSet::contains(const std::string& s) const
{
    int hash {hashFunction(s, BASE_TO_USE, capacity)};
    int i {0};

    while (true) {
        auto temp {hash};
        hash += fmod(i * i, capacity);
        hash = fmod(hash, capacity);

        if (get(hash) == s) {
            return true;
        }
        else if (i == count) {
            return false;
        }

        hash = temp;
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
