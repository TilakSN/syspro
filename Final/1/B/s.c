#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include <stdlib.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main() {
	int fd, n;
	char buf[256];
	umask(0);
	mknod("FooBar", S_IFIFO | 0666, 0);
	printf("Ready to listen.\n");
	while (1) {
		if ((fd = open("FooBar", O_RDONLY)) < 0)
			_err("Opening file");
		n = read(fd, buf, 256);
		buf[n] = 0;
		printf("Received: %s\n", buf);
		close(fd);
	}
	return 0;
}