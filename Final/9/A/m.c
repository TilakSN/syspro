#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void display(char *name) {
	printf("%-13s PID: %6d, PPID: %6d\n", name, getpid(), getppid());
}

int main() {
	int pid = fork();
	if (!pid) {
		// child
		pid = fork();
		if (pid > 0) {
			display("Child");
			// child exits = grandchild becomes orphan
			return 0;
		}
		if (pid == 0) {
			display("Grandchild");
			// grandchild stays for long
			sleep(5);
			printf("\nOrphan:\n");
			display("Grandchild");
			system("ps -aux | grep user");
			return 0;
		}
		// fork failed
	}
	else if (pid > 0) {
		// parent
		display("Parent");
		sleep(2); // waits for child to exit
		printf("\nZombie:\n");
		system("ps -aux | grep Z");
		sleep(4);
		display("Parent");
		return 0; // exits without join() => child is zombie
	}
	// fork failed
	fprintf(stderr, "Error: Fork failed.\n");
	return 1;	
}