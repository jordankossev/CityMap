#include "ThreeShortestPathsCommand.h"

ThreeShortestPathsCommand::ThreeShortestPathsCommand(Graph*g) : ICommand(g) {
}

void ThreeShortestPathsCommand::execute() {
	std::string from, to;
	std::cin >> from >> to;

	if (!g->hasVertex(from)) {
		std::cout << "Junction " << from << " does not exist!\n";
		return;
	}
	if (!g->hasVertex(to)) {
		std::cout << "Junction " << to << " does not exist!\n";
		return;
	}

	size_t closedJunctionsCount;
	std::cout << "Enter the number of closed junctions: ";
	std::cin >> closedJunctionsCount;

	if (closedJunctionsCount > 0) {
		std::vector<std::string> closedJunctions;

		std::cout << "Specify the closed junctions: ";
		while (closedJunctionsCount > 0) {
			std::string junction;
			std::cin >> junction;
			closedJunctions.push_back(junction);
			closedJunctionsCount--;
		}

		g->threeShortestPaths(from, to, closedJunctions);
	}
	else {
		g->threeShortestPaths(from, to);
	}
}

std::string ThreeShortestPathsCommand::stringID() {
	return "three-shortest-paths";
}
