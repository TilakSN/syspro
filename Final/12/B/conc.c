#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	char a[1024], b[1024], line[2048];
	int n;
	while ((n = read(STDIN_FILENO, line, 2048)) > 0) {
		line[n] = 0;
		if (sscanf(line, "%s%s", a, b) == 2)
			sprintf(line, "%s%s", a, b);
		else
			sprintf(line, "Invalid");
		write(STDOUT_FILENO, line, strlen(line));
	}
	return 0;
}