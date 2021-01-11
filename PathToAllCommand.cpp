#include "PathToAllCommand.h"

PathToAllCommand::PathToAllCommand(Graph* g) : ICommand(g) {
}

void PathToAllCommand::execute() {
	std::string vertex;
	std::cin >> vertex;
	if (!g->hasVertex(vertex)) {
		std::cout << "Junction " << vertex << " does not exist!\n";
		return;
	}

	if (g->existsPathToAll(vertex)) {
		std::cout << "yes\n";
	}
	else {
		std::cout << "no\n";
	}
}

std::string PathToAllCommand::stringID() {
	return "path-to-all";
}
