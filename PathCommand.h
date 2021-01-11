#ifndef __PATH_COMMAND_H
#define __PATH_COMMAND_H

#include <iostream>

#include "ICommand.h"

class PathCommand : public ICommand {
public:
	PathCommand(Graph*);
	void execute();
	std::string stringID();
};

#endif // !__PATH_COMMAND_H
