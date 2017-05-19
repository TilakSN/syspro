#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main() {
	char filename[256], c;
	printf("Enter filename: ");
	scanf("%s", filename);
	int fd, n;
	if ((fd = open(filename, O_RDONLY)) < 0)
		_err("Opening file");
	n = lseek(fd, -1, SEEK_END) + 1;
	while (n--) {
		if (read(fd, &c, 1) < 0)
			_err("Reading file");
		if (write(STDOUT_FILENO, &c, 1) != 1)
			_err("Writing to STDOUT");
		lseek(fd, -2, SEEK_CUR);
	}
	printf("\n");
	return 0;
}