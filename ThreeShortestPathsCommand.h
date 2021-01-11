#ifndef __THREE_SHORTEST_PATHS_COMMAND_H
#define __THREE_SHORTEST_PATHS_COMMAND_H

#include "ICommand.h"

class ThreeShortestPathsCommand : public ICommand {
public:
	ThreeShortestPathsCommand(Graph*);

	void execute();
	std::string stringID();
};

#endif // !__THREE_SHORTEST_PATHS_COMMAND_H