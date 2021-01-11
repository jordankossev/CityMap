#ifndef __PATH_TO_ALL_COMMAND_H
#define __PATH_TO_ALL_COMMAND_H

#include "ICommand.h"

class PathToAllCommand : public ICommand {
public:
	PathToAllCommand(Graph*);

	void execute();
	std::string stringID();
};

#endif // !__PATH_TO_ALL_COMMAND_H