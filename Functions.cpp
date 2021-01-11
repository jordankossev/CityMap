#ifndef __FUNCTIONS_CPP
#define __FUNCTIONS_CPP

#include <iostream>

#include "Functions.h"

bool vectorContains(const std::vector<PAIR>& vector, const std::string& elem) {
	for (size_t i = 0; i < vector.size(); i++) {
		if (vector[i].first == elem) {
			return true;
		}
	}

	return false;
}

size_t pathWeight(const std::vector<PAIR>& path) {
	size_t sum = 0;
	for (size_t i = 0; i < path.size(); i++) {
		sum += path[i].second;
	}

	return sum;
}

void printPath(const std::vector<PAIR>& path) {
	for (size_t i = 0; i < path.size(); i++) {
		std::cout << path[i].first << " ";
	}
	std::cout << std::endl;
}

void printManyPaths(const std::vector<std::vector<PAIR>>& paths) {
	for (size_t i = 0; i < paths.size(); i++) {
		printPath(paths[i]);
	}
}

bool isShorter(const std::vector<PAIR>& p, const std::vector<PAIR>& q) {
	size_t pWeight = pathWeight(p), qWeight = pathWeight(q);
	if (pWeight == qWeight) {
		return p.size() < q.size();
	}
	return pWeight < qWeight;
}

#endif // !__FUNCTIONS_CPP