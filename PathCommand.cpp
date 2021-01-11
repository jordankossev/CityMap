#include "PathCommand.h"

PathCommand::PathCommand(Graph* g) : ICommand(g) {
}

std::string PathCommand::stringID() {
	return "path";
}

void PathCommand::execute() {
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
	g->existsPath(from, to);
}