#ifndef __INVOKER_H
#define __INVOKER_H

#include "Graph.h"
#include "ICommand.h"
#include "LoadCommand.h"
#include "PathCommand.h"
#include "ThreeShortestPathsCommand.h"
#include "CycleCommand.h"
#include "TouristPathCommand.h"
#include "PathToAllCommand.h"
#include "DeadEndsCommand.h"
#include "ExitCommand.h"

/// \brief A class that will invoke commands
class Invoker {
private:
	Graph* g;
	std::vector<ICommand*> commands;
public:
	Invoker(Graph*);
	~Invoker();

	void executeCommand(const std::string&);
};

#endif // !__INVOKER_H