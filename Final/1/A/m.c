#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main() {
	int n, fd;
	char filename[256];
	printf("Enter file name: ");
	scanf("%s", filename);
	if ((fd = open(filename, O_RDWR | O_CREAT, 0666)) < 0)
		_err("Opening file");
	printf("Enter the number of characters: ");
	scanf("%d", &n);
	int buffer[n + 1];
	printf("Enter the characters:\n");
	if ((fd = dup2(fd, STDOUT_FILENO)) < 0)
		_err("Failed to duplicate");
	if (read(STDIN_FILENO, buffer, n) < n)
		_err("Reading input");
	if (write(STDOUT_FILENO, buffer, n) != n)
		_err("Writing to file");
	return 0;
}