#ifndef __EXIT_COMMAND_H
#define __EXIT_COMMAND_H

#include "ICommand.h"

class ExitCommand : public ICommand {
public:
	ExitCommand(Graph*);

	void execute();
	std::string stringID();
};

#endif // !__EXIT_COMMAND_H