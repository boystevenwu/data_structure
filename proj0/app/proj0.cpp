#include "proj0.hpp"


unsigned int getValue(std::string s, const std::map<char, unsigned> & mapping) {
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


bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping)
{
    for (const std::string& s : {s1, s2, s3}) {
        for (const char c : s) {
            if (!mapping.count(c)) {
                return false;
            }
        }
    }
    
    unsigned int sum = getValue(s1, mapping) + getValue(s2, mapping);
    return (sum == getValue(s3, mapping));
}
