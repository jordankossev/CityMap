#ifndef __TOURIST_PATH_COMMAND_H
#define __TOURIST_PATH_COMMAND_H

#include "ICommand.h"

class TouristPathCommand : public ICommand {
public:
	TouristPathCommand(Graph*);

	void execute();
	std::string stringID();
};

#endif // !__TOURIST_PATH_COMMAND_H