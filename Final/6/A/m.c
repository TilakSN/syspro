#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

void display_stat(struct stat *details) {
	printf("Access time       : %s", ctime(&details->st_atime));
	printf("Modification time : %s", ctime(&details->st_mtime));
	printf("Status change time: %s", ctime(&details->st_ctime));
}

int main() {
	char f1[256], f2[256];
	printf("Enter source and destination filenames:\n");
	scanf("%s%s", f1, f2);
	struct stat d1, d2;
	if (stat(f1, &d1))
		_err("Reading stat");
	printf("Source:\n");
	display_stat(&d1);
	struct utimbuf t = {d1.st_atime, d1.st_mtime};
	if (stat(f2, &d2))
		_err("Reading stat");
	printf("Destination before copy:\n");
	display_stat(&d2);
	utime(f2, &t);
	if (stat(f2, &d2))
		_err("Reading stat");
	printf("Destination after copy:\n");
	display_stat(&d2);
	return 0;
}