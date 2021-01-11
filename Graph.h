#ifndef __GRAPH_H
#define __GRAPH_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <cassert>

#include "Functions.h"

using ADJ_LIST = std::vector<std::vector<PAIR>>;

class Graph {
private:
	ADJ_LIST adjList;

	size_t vertexOutDegree(size_t);
	size_t vertexInDegree(size_t);
	bool hasEulerianPath(const std::vector<size_t>&, const std::vector<size_t>&);
	size_t eulerianPathStartingIndex(const std::vector<size_t>&, const std::vector<size_t>&);
	void eulerianDFS(size_t, std::vector<size_t>&, std::stack<size_t>&, std::vector<std::pair<size_t, size_t>>&);
	bool pathExistence(size_t, size_t, std::vector<bool>&) const;
	bool existsPathIndices(size_t, size_t) const;
public:
	void addVertex(const std::string&);
	void addEdge(const std::string&, const std::string&, size_t);
	bool hasVertex(const std::string&) const;
	size_t findVertex(const std::string&) const;

	void existsPath(const std::string&, const std::string&) const;
	bool isInCycle(const std::string&) const;
	bool existsPathToAll(const std::string&);
	void allWays(const std::string&, size_t, const std::string&, std::vector<PAIR>&, std::vector<std::vector<PAIR>>&);

	void threeShortestPaths(const std::string&, const std::string&);
	void threeShortestPaths(const std::string&, const std::string&, std::vector<std::string>&);

	void displayDeadEnds() const;
	void eulerianPath();

	void load(const std::string&);
};


#endif // !__GRAPH_H