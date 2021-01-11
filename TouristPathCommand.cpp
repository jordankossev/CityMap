#include "TouristPathCommand.h"

TouristPathCommand::TouristPathCommand(Graph*g) : ICommand(g) {
}

void TouristPathCommand::execute() {
	g->eulerianPath();
}

std::string TouristPathCommand::stringID() {
	return "tourist-path";
}
