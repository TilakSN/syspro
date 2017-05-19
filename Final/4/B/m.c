#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
	char directory[256], filename[300] = {};
	printf("Enter path: ");
	scanf("%s", directory);
	DIR *dir = opendir(directory);
	if (!dir) {
		fprintf(stderr, "Error opening directory.\n");
		return 1;
	}
	// strcpy can be avoided if opendir(".") is called.
	// copy is required to get relative path
	// cuz filename doesn't store the path.
	// But, if the file is in current directory, path is optional
	int n = strlen(directory);
	strcpy(filename, directory);
	filename[n++] = '/';
	struct stat details;
	struct dirent *file;
	while (file = readdir(dir)) {
		printf("%-50s", file->d_name);
		strcpy(filename + n, file->d_name);
		if (stat(filename, &details)) {
			fprintf(stderr, "Error getting stat.\n");
		}
		else
			printf(" %6lu %4d %10ld %3ld %7o", details.st_ino, details.st_uid, details.st_size, details.st_nlink, details.st_mode);
		printf("\n");
	}
	return 0;
}