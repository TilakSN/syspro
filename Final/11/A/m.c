#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main() {
	int pid;
	if ((pid = fork()) < 0)
		_err("Fork failed");
	if (pid) {
		// parent
		printf("PID of child: %d\n", pid);
		exit(EXIT_SUCCESS);
	}
	umask(0);
	if (chdir("/") < 0)
		_err("Failed to change directory");
	if (setsid() < 0)
		_err("Failed to create session");
	printf("Daemon created!\n");
	system("ps -axj | grep PPID");
	system("ps -axj | grep a.out");
	return 0;
}