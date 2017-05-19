#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler() {
	printf("Interrupt!!!\n");
	signal(SIGINT, SIG_DFL);
}

int main() {
	signal(SIGINT, SIG_IGN);
	int n = 5;
	while (n--) {
		printf("Press Ctrl+C, you'll be ignored :P\n");
		sleep(1);
	}
	signal(SIGINT, handler);
	while (1) {
		printf("Press Ctrl+C again\n");
		sleep(1);
	}
	return 0;
}