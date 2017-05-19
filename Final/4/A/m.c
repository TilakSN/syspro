#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main() {
	int cs_pipe[2], sc_pipe[2], pid, n;
	char buf[256];
	if (pipe(cs_pipe) || pipe(sc_pipe))
		_err("Creating pipes");
	if ((pid = fork()) < 0)
		_err("Fork failed");
	if (pid) { // parent
		close(cs_pipe[0]);
		close(sc_pipe[1]);
		printf("Make sure you do 'gcc add.c -o add'\nPress Ctrl+C to exit\n");
		printf("Enter 2 numbers in each line, separated by space.\n");
		while ((n = read(STDIN_FILENO, buf, 256)) > 0) {
			buf[n] = 0;
			if (write(cs_pipe[1], buf, n) != n)
				_err("Write to pipe");
			if ((n = read(sc_pipe[0], buf, 256)) < 0)
				_err("Read from pipe");
			buf[n] = 0;
			printf("Result: %s\n", buf);
		}
		close(cs_pipe[1]);
		close(sc_pipe[0]);
	}
	else { // child
		close(cs_pipe[1]);
		close(sc_pipe[0]);
		if (dup2(cs_pipe[0], STDIN_FILENO) != STDIN_FILENO || dup2(sc_pipe[1], STDOUT_FILENO) != STDOUT_FILENO)
			_err("Dup2 failed");
		close(cs_pipe[0]);
		close(sc_pipe[1]);
		execl("./add", "add", (char *) NULL);
	}
	return 0;
}