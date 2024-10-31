#include <signal.h> // для signal()

#include "closecore.hpp"

volatile sig_atomic_t signal_status = 0;

void sighandler(int s) {
	signal_status = s;
}

void SetSignals() {
	signal(SIGINT, sighandler);  // когда нажимаем Ctrl+C
	signal(SIGQUIT, sighandler); // когда нажимаем Ctrl+'\'
	signal(SIGWINCH, sighandler); // когда изменяется размер терминала
	signal(SIGTSTP, sighandler); // когда нажимаем Ctrl+Z
}

void CheckSignals() {
	if (signal_status && signal_status != SIGWINCH)
		CloseProgram();
}

