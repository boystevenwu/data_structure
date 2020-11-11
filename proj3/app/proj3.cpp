#include "proj3.hpp"
#include "Wordset.hpp"
#include <set>
#include <sstream>
#include <map>
#include <stack>
#include <queue>

// You should not need to change this function.
void loadWordsIntoTable(WordSet & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;

	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}
}


void bfs(const std::string& s2, bool& indicator, std::map<std::string, std::string>& relation,
         std::queue<std::string>& queue, std::set<std::string>& visited,
         const std::set<char>& ALPHABETS, const WordSet& words) {
    auto word {queue.front()};
    queue.pop();
    visited.insert(word);

    for (int i = 0; i < word.length(); i++) {
        auto temp {word};

        for (char c : ALPHABETS) {
            temp[i] = c;

            if (words.contains(temp) && (visited.find(temp) == visited.end()) && indicator) {
                queue.push(temp);
                relation.insert({temp, word});

                if (temp == s2) { indicator = false; }
            }
        }
    }
}

// You probably want to change this function.
std::string convert(const std::string& s1, const std::string& s2, const WordSet & words)
{
    const std::set<char> ALPHABETS {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
                                    111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
    std::map<std::string, std::string> relation;
    std::queue<std::string> queue;
    std::set<std::string> visited;
    bool indicator {true};
    queue.push(s1);

    while (indicator) {
        bfs(s2, indicator, relation, queue, visited, ALPHABETS, words);
    }

    std::string bird {s2};
    std::stack<std::string> eagle;
    std::stringstream result;
    while (bird != s1) {
        eagle.push(bird);
        bird = relation.find(bird)->second;
    }
    while (bird != s2) {
        result << bird << " --> ";
        bird = eagle.top();
        eagle.pop();
    }
    result << bird;

	return result.str();
}
