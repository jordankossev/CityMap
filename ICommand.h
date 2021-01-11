#ifndef __ICOMMAND_H
#define __ICOMMAND_H

#include "Graph.h"

class ICommand {
protected:
	Graph* g;
public:
	ICommand(Graph*);

	virtual void execute() = 0;
	virtual std::string stringID() = 0;
};


#endif // !__ICOMMAND_H