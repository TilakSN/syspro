#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler() {
	printf("Handler: PID = %d\n", getpid());
}

int main() {
	int pid;
	signal(SIGALRM, handler);
	alarm(2);
	if ((pid = fork()) < 0) {
		fprintf(stderr, "Error: Fork failed.\n");
		return 1;
	}
	if (pid)
		printf("Parent: %d\n", getpid());
	else
		printf("Child: %d\n", getpid());
	sleep(3);
	return 0;
}