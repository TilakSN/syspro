#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

int main() {
	char filename[256];
	printf("Enter filename: ");
	scanf("%s", filename);
	struct stat details;
	if (stat(filename, &details))
		_err("Getting stat");
	printf("Device ID      : %lu\n", details.st_dev);
	printf("Inode number   : %lu\n", details.st_ino);
	printf("Mode           : %o\n", details.st_mode);
	printf("Number of links: %lu\n", details.st_nlink);
	printf("UID            : %d\n", details.st_uid);
	printf("GID            : %d\n", details.st_gid);
	printf("Size           : %ld\n", details.st_size);
	return 0;
}