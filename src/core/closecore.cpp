#include <cstdlib> // для exit()
#include <iostream>

void BeforeCloseProgram();

void ErrorCloseProgram(const char* message) {
	BeforeCloseProgram();
	printf("Ошибка: %s\n", message);

	exit(1);
}

[[noreturn]] void CloseProgram() {
	BeforeCloseProgram();

	exit(0);
}

