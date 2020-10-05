#include <iostream>
#include <map>
#include <string>


auto getValue(std::string s, const std::map<char, unsigned> & mapping) {
    unsigned int result = 0;
    unsigned int len = s.length();

    for (int i = len-1; i >= 0; --i) {
        unsigned int v = mapping.at(s[i]);
        
        unsigned int j = 1;
        while (j < len-i) {
            v *= 10;
            ++j;
        }
        result += v;
    }

    return result;
}


int main() {
    std::map<char, unsigned> solution = { {'A', 7}, {'B', 5},
            {'I', 0}, {'N', 4}, {'O', 3}, {'P', 2}, {'T', 1}
            };
    std::cout << getValue("PABIN", solution);
}

