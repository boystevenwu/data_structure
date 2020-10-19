//
// Created by Steven Wu on 10/15/20.
//

#pragma once

#include <string>
#include <map>

bool puzzleSolver(const std::string& s1, const std::string& s2, const std::string& s3, std::map<char, unsigned> & mapping);

bool checkMap(const std::string& s1, const std::string& s2, const std::string& s3, std::map<char, unsigned> & mapping);
