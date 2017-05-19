#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
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
	int n = strlen(directory);
	strcpy(filename, directory);
	filename[n++] = '/';
	struct stat details;
	struct dirent *file;
	while (file = readdir(dir)) {
		strcpy(filename + n, file->d_name);
		if (stat(filename, &details)) {
			fprintf(stderr, "Error getting stat for '%s'.\n", file->d_name);
		}
		else if (!details.st_size) {
			unlink(filename);
			printf("Deleted file: '%s'\n", file->d_name);
		}
	}
	return 0;
}