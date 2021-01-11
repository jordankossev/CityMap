#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include <vector>
#include <string>

using PAIR = std::pair<std::string, size_t>;

bool vectorContains(const std::vector<PAIR>&, const std::string&);
size_t pathWeight(const std::vector<PAIR>&);
void printPath(const std::vector<PAIR>&);
void printManyPaths(const std::vector<std::vector<PAIR>>&);
bool isShorter(const std::vector<PAIR>&, const std::vector<PAIR>&);

#endif // !__FUNCTIONS_H

