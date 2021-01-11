#ifndef __DEAD_ENDS_COMMAND_H
#define __DEAD_ENDS_COMMAND_H

#include "ICommand.h"

class DeadEndsCommand : public ICommand {
public:
	DeadEndsCommand(Graph*);

	void execute();
	std::string stringID();
};

#endif // !__DEAD_ENDS_COMMAND_H