#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main() {
	char buf[256];
	int cs_pipe[2], sc_pipe[2], pid, n;
	// xy_pipe = x reads, y writes
	// x closes 1, y closes 0
	if (pipe(cs_pipe) || pipe(sc_pipe))
		_err("Creating pipes");
	if ((pid = fork()) < 0)
		_err("Fork failed");
	if (pid) { // parent: server
		close(cs_pipe[0]);
		close(sc_pipe[1]);
		if ((n = read(sc_pipe[0], buf, 256)) < 0)
			_err("(Server) Reading from pipe");
		if (buf[0] >= 'a' && buf[0] <= 'z')
			buf[0] -= 32;
		if (write(cs_pipe[1], buf, n) != n)
			_err("(Server) Write to pipe");
		close(cs_pipe[1]);
		close(sc_pipe[0]);
	}
	else { // child: client
		close(cs_pipe[1]);
		close(sc_pipe[0]);
		printf("Enter a string: ");
		scanf("%s", buf);
		n = strlen(buf);
		if (write(sc_pipe[1], buf, n) != n)
			_err("(Client) Write to pipe");
		if ((n != read(cs_pipe[0], buf, n)))
			_err("(Client) Reading from pipe");
		buf[n] = 0;
		printf("Uppercase: %s\n", buf);
		close(cs_pipe[0]);
		close(sc_pipe[1]);
	}
	return 0;
}