#ifndef __LOAD_COMMAND_H
#define __LOAD_COMMAND_H

#include "ICommand.h"

class LoadCommand : public ICommand {
public:
	LoadCommand(Graph* g);

	void execute();
	std::string stringID();
};

#endif // !__LOAD_COMMAND_H