#include "LoadCommand.h"

LoadCommand::LoadCommand(Graph* g) : ICommand(g) {
}

void LoadCommand::execute() {
	std::string fileName;
	std::cin >> fileName;
	g->load(fileName);
}

std::string LoadCommand::stringID() {
	return "load";
}
