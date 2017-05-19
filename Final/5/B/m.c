#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction sigbuf;

void handler(int val) {
	printf("Interrupt!!!\n");
	sigbuf.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sigbuf, NULL);
}

int main() {
	sigbuf.sa_flags = 0;
	sigemptyset(&sigbuf.sa_mask);
	sigaddset(&sigbuf.sa_mask, SIGINT);
	sigbuf.sa_handler = handler;
	sigaction(SIGINT, &sigbuf, NULL);
	while (1) {
		printf("Press Ctrl+C\n");
		sleep(1);
	}
	return 0;
}