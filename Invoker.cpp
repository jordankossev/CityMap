#include "Invoker.h"

Invoker::Invoker(Graph* g) : g(g) {
	commands.push_back(new LoadCommand(g));
	commands.push_back(new PathCommand(g));
	commands.push_back(new ThreeShortestPathsCommand(g));
	commands.push_back(new CycleCommand(g));
	commands.push_back(new TouristPathCommand(g));
	commands.push_back(new PathToAllCommand(g));
	commands.push_back(new DeadEndsCommand(g));
	commands.push_back(new ExitCommand(g));
}

Invoker::~Invoker() {
	for (size_t i = 0; i < commands.size(); i++) {
		delete commands[i];
	}
}

void Invoker::executeCommand(const std::string& input) {
	for (size_t i = 0; i < commands.size(); i++) {
		if (commands[i]->stringID() == input) {
			commands[i]->execute();
			return;
		}
	}
	std::cout << "Invalid command!\n";
}