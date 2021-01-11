#include <iostream>

#include "Invoker.h"

int main() {
	Graph cityMap;
	Invoker invoker(&cityMap);
	std::string input;
	while (true) {
		std::cin >> input;
		invoker.executeCommand(input);
	}
}