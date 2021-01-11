#ifndef __CYCLE_COMMAND_H
#define __CYCLE_COMMAND_H

#include "ICommand.h"

class CycleCommand : public ICommand {
public:
	CycleCommand(Graph*);

	void execute();
	std::string stringID();
};

#endif // !__CYCLE_COMMAND_H