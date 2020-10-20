//
// Created by Steven Wu on 10/15/20.
//

#include "proj1.hpp"
#include <iostream>
#include <set>
#include <queue>
#include <list>

bool checkMap(const std::string& s1, const std::string& s2, const std::string& s3, const std::map<char, unsigned>& mapping) {
    std::queue<unsigned int> numbers;

    for (const std::string& s : {s1, s2, s3}) {
        std::string num;
        for (char c : s) {
            num += std::to_string(mapping.at(c));
        }
        numbers.push(stoi(num));
    }

    unsigned int a = numbers.front();
    numbers.pop();
    unsigned int b = numbers.front();
    numbers.pop();
    unsigned int c = numbers.front();
    numbers.pop();

    return (a + b == c);
}

std::map<char, unsigned> worker(const std::string& s1, const std::string& s2, const std::string& s3,const std::set<char>& all_letters,
                                const std::list<unsigned int>& numbers, const std::queue<unsigned int>& queue) {
    std::list<unsigned int> num_temp = numbers;
    static unsigned int hold {10};
    std::map<char, unsigned> map_temp, result;

    for (const unsigned int n : numbers) {
        auto que_temp = queue;
        que_temp.push(n);
        num_temp.remove(n);

        if (hold < 10) {
            auto itr = num_temp.begin();
            num_temp.insert(itr, hold);
            hold = 10;
        }

        if (que_temp.size() == all_letters.size()) {
            for (const char c : all_letters) {
                map_temp[c] = que_temp.front();
                que_temp.pop();
            }

            if (checkMap(s1, s2, s3, map_temp)) {
                return map_temp;
            }
        }
        else {
            result = worker(s1, s2, s3, all_letters, num_temp, que_temp);
        }

        hold = n;
        
        if (!result.empty()) {
            return result;
        }
    }

    return result;
}

bool puzzleSolver(const std::string& s1, const std::string& s2, const std::string& s3, std::map<char, unsigned>& mapping) {
    std::list<unsigned int> numbers {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::queue<unsigned int> queue;
    std::set<char> all_letters;
    for (const std::string& s : {s1, s2, s3}) {
        for (char c : s) {
            all_letters.insert(c);
        }
    }

    mapping = worker(s1, s2, s3, all_letters, numbers, queue);

    if (mapping.empty()) {
        return false;
    }
    else {
        for (auto item : mapping) {
            std::cout << item.first << item.second << " ";
        }
        return checkMap(s1, s2, s3, mapping);
    }
}
