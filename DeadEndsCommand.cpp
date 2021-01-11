#include "DeadEndsCommand.h"

DeadEndsCommand::DeadEndsCommand(Graph* g) : ICommand(g) {
}

void DeadEndsCommand::execute() {
	g->displayDeadEnds();
}

std::string DeadEndsCommand::stringID() {
	return "dead-ends";
}
