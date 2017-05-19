#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main() {
	int cs_pipe[2], sc_pipe[2], pid, n;
	char line[2048];
	if (pipe(cs_pipe) || pipe(sc_pipe))
		_err("Pipe creation failed");
	if ((pid = fork()) < 0)
		_err("Fork failed");
	if (pid) {
		close(cs_pipe[0]);
		close(sc_pipe[1]);
		printf("Make sure conc.c is compiled to 'conc'\n");
		printf("Enter 2 strings separated by space in each line:\n");
		while ((n = read(STDIN_FILENO, line, 2048)) > 0) {
			if (write(cs_pipe[1], line, n) != n)
				_err("Write to pipe failed");
			if ((n = read(sc_pipe[0], line, 2048)) <= 0)
				_err("Read from pipe failed");
			line[n] = 0;
			printf("Result: %s\n", line);
		}
		close(cs_pipe[1]);
		close(sc_pipe[0]);
	}
	else {
		close(cs_pipe[1]);
		close(sc_pipe[0]);
		if (dup2(cs_pipe[0], STDIN_FILENO) != STDIN_FILENO || dup2(sc_pipe[1], STDOUT_FILENO) != STDOUT_FILENO)
			_err("Duplication failed");
		close(cs_pipe[0]);
		close(sc_pipe[1]);
		execl("./conc", "conc", (char *) NULL);
	}
	return 0;
}