#include "ExitCommand.h"

ExitCommand::ExitCommand(Graph* g)  : ICommand(g) {
}

void ExitCommand::execute() {
	std::exit(0);
}

std::string ExitCommand::stringID() {
	return "exit";
}
