#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
	int fd, n;
	char buf[256];
	if ((fd = open("FooBar", O_RDWR)) < 0)
		_err("Opening file");
	if (argc < 2)
		_err("Argument missing");
	n = strlen(argv[1]);
	if (write(fd, argv[1], n) != n)
		_err("Write to file");
	close(fd);
	return 0;
}