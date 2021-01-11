#ifndef __GRAPH_CPP
#define __GRAPH_CPP

#include "Graph.h"

size_t Graph::vertexOutDegree(size_t index) {
	return adjList[index].size() - 1;
}

size_t Graph::vertexInDegree(size_t index) {
	std::string vertexName = adjList[index][0].first;
	size_t inDegree = 0;

	for (size_t i = 0; i < adjList.size(); i++) {
		if (vectorContains(adjList[i], vertexName)) {
			inDegree++;
		}
	}

	return inDegree - 1;
}

bool Graph::hasEulerianPath(const std::vector<size_t>& outDegrees, const std::vector<size_t>& inDegrees) {
	size_t startingVerticesCount = 0, endingVerticesCount = 0;

	for (size_t i = 0; i < outDegrees.size(); i++) {
		int outDiff = outDegrees[i] - inDegrees[i];
		int inDiff = inDegrees[i] - outDegrees[i];

		if (outDiff > 1 || inDiff > 1) {
			return false;
		}
		if (outDegrees[i] - inDegrees[i] == 1) {
			startingVerticesCount++;
		}
		else if (inDegrees[i] - outDegrees[i] == 1) {
			endingVerticesCount++;
		}
	}

	return (startingVerticesCount == 0 && endingVerticesCount == 0)
		|| (startingVerticesCount == 1 && endingVerticesCount == 1);
}

size_t Graph::eulerianPathStartingIndex(const std::vector<size_t>& outDegrees, const std::vector<size_t>& inDegrees) {
	size_t startingIndex = 0;

	for (size_t i = 0; i < outDegrees.size(); i++) {
		if (outDegrees[i] - inDegrees[i] == 1) {
			return i;
		}
		if (outDegrees[i] > 0) {
			startingIndex = i;
		}
	}

	return startingIndex;
}

void Graph::eulerianDFS(size_t currentVertexIndex, std::vector<size_t>& outDegrees, std::stack<size_t>& path, std::vector<std::pair<size_t, size_t>>& visitedEdges) {
	if (outDegrees[currentVertexIndex] > 0) {
		for (size_t i = 1; i < adjList[currentVertexIndex].size(); i++) {
			size_t nextVertexIndex = findVertex(adjList[currentVertexIndex][i].first);

			std::vector<std::pair<size_t, size_t>>::iterator it
				= std::find(visitedEdges.begin(), visitedEdges.end(), std::make_pair(currentVertexIndex, nextVertexIndex));
			if (it == visitedEdges.end()) {
				visitedEdges.push_back(std::make_pair(currentVertexIndex, nextVertexIndex));
				outDegrees[currentVertexIndex]--;
				eulerianDFS(nextVertexIndex, outDegrees, path, visitedEdges);
			}
		}
	}
	path.push(currentVertexIndex);

	return;
}

bool Graph::pathExistence(size_t fromIndex, size_t toIndex, std::vector<bool>& visited) const {
	visited[fromIndex] = true;
	if (fromIndex == toIndex) {
		return true;
	}

	for (size_t i = 1; i < adjList[fromIndex].size(); i++) {
		size_t nextIndex = findVertex(adjList[fromIndex][i].first);
		if (!visited[nextIndex] && pathExistence(nextIndex, toIndex, visited)) {
			return true;
		}
	}

	return false;
}

bool Graph::existsPathIndices(size_t fromIndex, size_t toIndex) const {
	std::vector<bool> visited(adjList.size(), 0);
	return pathExistence(fromIndex, toIndex, visited);
}

void Graph::addVertex(const std::string& vertex) {
	std::vector<PAIR> newVertexVector;
	newVertexVector.push_back(std::make_pair(vertex, 0));
	adjList.push_back(newVertexVector);
}

void Graph::addEdge(const std::string& from, const std::string& to, size_t weight) {
	for (size_t i = 0; i < adjList.size(); i++) {
		PAIR p = *(adjList[i].begin());
		if (p.first == from) {
			adjList[i].push_back(std::make_pair(to, weight));
			return;
		}
	}
}

bool Graph::hasVertex(const std::string& vertex) const {
	for (size_t i = 0; i < adjList.size(); i++) {
		PAIR p = *(adjList[i].begin());
		if (p.first == vertex) {
			return true;
		}
	}

	return false;
}

size_t Graph::findVertex(const std::string& vertex) const { // assert hasVertex
	for (size_t i = 0; i < adjList.size(); i++) {
		PAIR p = *(adjList[i].begin());
		if (p.first == vertex) {
			return i;
		}
	}
}

void Graph::existsPath(const std::string& from, const std::string& to) const {
	size_t fromIndex = findVertex(from), toIndex = findVertex(to);

	if (existsPathIndices(fromIndex, toIndex)) {
		std::cout << "yes\n";
	}
	else {
		std::cout << "no\n";
	}
}

bool Graph::isInCycle(const std::string& vertex) const {
	size_t fromIndex = findVertex(vertex);
	std::vector<bool> visited(adjList.size(), 0);

	for (size_t i = 1; i < adjList[fromIndex].size(); i++) {
		size_t nextIndex = findVertex(adjList[fromIndex][i].first);
		if (!visited[nextIndex] && pathExistence(nextIndex, fromIndex, visited)) {
			return true;
		}
	}

	return false;
}

bool Graph::existsPathToAll(const std::string& vertex) {
	size_t fromIndex = findVertex(vertex);

	for (size_t i = 0; i < adjList.size(); i++) {
		if (!existsPathIndices(fromIndex, i)) {
			return false;
		}
	}

	return true;
}

void Graph::allWays(const std::string& from, size_t currentWeight, const std::string& to, std::vector<PAIR>& path, std::vector<std::vector<PAIR>>& allPaths) {
	size_t index = findVertex(from);
	PAIR p = *(adjList[index].begin());
	p.second = currentWeight;
	path.push_back(p);

	if (from == to) {
		allPaths.push_back(path);
	}
	else {
		std::vector<PAIR>::iterator it = adjList[index].begin();
		++it;
		for (it; it != adjList[index].end(); ++it) {
			if (!vectorContains(path, (*it).first)) {
				allWays((*it).first, (*it).second, to, path, allPaths);
			}
		}
	}

	path.pop_back();
}

void Graph::threeShortestPaths(const std::string& from, const std::string& to) {
	std::vector<PAIR> path;
	std::vector<std::vector<PAIR>> allPaths;

	allWays(from, 0, to, path, allPaths);
	std::sort(allPaths.begin(), allPaths.end(), isShorter);

	std::vector<std::vector<PAIR>> threeShortestPaths;
	size_t i = 0;
	while (i < allPaths.size() && i < 3) {
		threeShortestPaths.push_back(allPaths[i]);
		i++;
	}

	printManyPaths(threeShortestPaths);
	return;
}

void Graph::threeShortestPaths(const std::string& from, const std::string& to, std::vector<std::string>& closedVertices) {
	std::vector<PAIR> path;
	std::vector<std::vector<PAIR>> allPaths;

	allWays(from, 0, to, path, allPaths);
	std::sort(allPaths.begin(), allPaths.end(),
		[](std::vector<PAIR>& p, std::vector<PAIR>& q) -> bool { return pathWeight(p) < pathWeight(q); });

	std::vector<std::vector<PAIR>> threeShortestPaths;
	size_t i = 0, shortestPathsCount = 0;
	while (i < allPaths.size() && shortestPathsCount < 3) {
		bool contains = false;
		size_t j = 0;
		while (!contains && j < closedVertices.size()) {
			if (vectorContains(allPaths[i], closedVertices[j])) {
				contains = true;
			}
			j++;
		}
		if (!contains) {
			threeShortestPaths.push_back(allPaths[i]);
			shortestPathsCount++;
		}
		i++;
	}

	printManyPaths(threeShortestPaths);
	return;
}

void Graph::displayDeadEnds() const {
	std::cout << "Dead ends:\n";
	size_t deadEndsCount = 0;
	for (size_t i = 0; i < adjList.size(); i++) {
		for (size_t j = 1; j < adjList[i].size(); j++) {
			size_t successorIndex = findVertex(adjList[i][j].first);
			if (adjList[successorIndex].size() == 1) {
				std::cout << adjList[i][0].first << " -> " << adjList[successorIndex][0].first << std::endl;
				deadEndsCount++;
			}
		}
	}

	if (deadEndsCount == 0) {
		std::cout << "There are no dead ends in the city\n";
	}
}

void Graph::eulerianPath() {
	std::vector<size_t> outDegrees, inDegrees;
	size_t edgesCount = 0;

	for (size_t i = 0; i < adjList.size(); i++) {
		outDegrees.push_back(vertexOutDegree(i));
		inDegrees.push_back(vertexInDegree(i));
		edgesCount += outDegrees[i];
	}

	if (!hasEulerianPath(outDegrees, inDegrees)) {
		std::cout << "No such path\n";
		return;
	}

	std::stack<size_t> path;
	std::vector<std::pair<size_t, size_t>> visitedEdges;
	size_t startingIndex = eulerianPathStartingIndex(outDegrees, inDegrees);
	eulerianDFS(startingIndex, outDegrees, path, visitedEdges);

	if (path.size() != (edgesCount + 1)) {
		std::cout << "No such path\n";
		return;
	}

	while (!path.empty()) {
		size_t index = path.top();
		std::cout << adjList[index][0].first << " ";
		path.pop();
	}
	std::cout << std::endl;
}

void Graph::load(const std::string& inputFileName) {
	assert(adjList.size() == 0);
	std::ifstream file(inputFileName, std::ios::in | std::ios::beg);
	assert(file);
	std::string line;

	size_t i = 0;
	while (getline(file, line)) {
		std::stringstream ss(line);
		std::string root;
		ss >> root;

		std::vector<PAIR> vertex;
		vertex.push_back(std::make_pair(root, 0));
		std::string neighbour;
		size_t weight;
		while (ss >> neighbour >> weight) {
			vertex.push_back(std::make_pair(neighbour, weight));
		}
		adjList.push_back(vertex);
	}
}

#endif // !__GRAPH_CPP