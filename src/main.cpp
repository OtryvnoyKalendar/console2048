#include "closecore.hpp"
#include "init.hpp"
#include "logic.hpp"

int main() {
	InitAll();

	while(1) {
		GameLogic();
	}
	
	CloseProgram();
	return 0;
}

