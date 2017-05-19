#include <stdio.h>
#include <unistd.h>

int main() {
	int pid, i;
	if ((pid = fork()) < 0) {
		fprintf(stderr, "Error: Fork failed.\n");
		return 1;
	}
	if (pid) {
		for (i = -1; ++i < 26; usleep(100000))
			printf("\t\t%c\n", (char) i + 'A');
	}
	else {
		for (i = -1; ++i < 26; usleep(100000))
			printf("\t\t%c\n", (char) i + 'a');
	}
	return 0;
}