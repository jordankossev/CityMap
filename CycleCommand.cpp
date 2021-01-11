#include "CycleCommand.h"

CycleCommand::CycleCommand(Graph* g) : ICommand(g) {
}

void CycleCommand::execute() {
	std::string vertex;
	std::cin >> vertex;

	if (!g->hasVertex(vertex)) {
		std::cout << "Junction " << vertex << " does not exist!\n";
		return;
	}

	if (g->isInCycle(vertex)) {
		std::cout << "yes\n";
	}
	else {
		std::cout << "no\n";
	}
}

std::string CycleCommand::stringID() {
	return "cycle";
}
