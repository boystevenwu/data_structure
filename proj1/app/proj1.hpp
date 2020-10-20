#ifndef __PROJ_1__HPP
#define __PROJ_1__HPP

/* 
 * Project 1:  you need to implement this function.
 I promise that any of my test cases will have an empty 
 	map as the fourth parameter when called.
 If the puzzle IS solvable, return true AND make the mapping indicate the solution.
 If the puzzle is NOT solvable, it is enough to return false.

 See the project 1 write-up for a better description. 
 */


#include <string>
#include <map>

bool puzzleSolver(const std::string& s1, const std::string& s2, const std::string& s3, std::map<char, unsigned> & mapping);

bool checkMap(const std::string& s1, const std::string& s2, const std::string& s3, const std::map<char, unsigned> & mapping);

#endif