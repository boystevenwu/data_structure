#include "Wordset.hpp"

const int BASE_TO_USE = 41; 
const double LOAD_LIMIT = 0.27;


// returns s, as a number in the given base, mod the given modulus
int hashFunction(const std::string& item)
{
    int result = 0;
    for (char i : item) {
        result += (int)i;
    }
    return result;
}


WordSet::WordSet() : capacity{ 10 }, count{ 0 }, hash_table{ new Node[capacity] } {

}

WordSet::~WordSet() = default;

std::string WordSet::get(int hash) const {
    return hash_table[hash % 10].item;
}

void WordSet::print() const {
    for (int i = 0; i < capacity; ++i) {
        std::cout << hash_table[i].item << " | ";
    }
    std::cout << std::endl;
}

void WordSet::insert(const std::string& s)
{
    int hash {hashFunction(s)};
    int i {0};

    while (true) {
        hash += i * i;
        std::cout << hash % 10 << " ";
        if (get(hash).empty()) {
            std::cout << std::endl;
            break;
        }
        else {
            hash -= i * i;
            i ++;
        }
    }


    hash_table[hash % 10] = Node(s, i);
    count ++;
}


bool WordSet::contains(const std::string& s) const
{
    int hash {hashFunction(s)};
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
