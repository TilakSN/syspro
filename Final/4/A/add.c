#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	int a, b;
	char line[256];
	while ((a = read(STDIN_FILENO, line, 256)) > 0) {
		line[a] = 0;
		if (sscanf(line, "%d%d", &a, &b) == 2)
			sprintf(line, "%d", a + b);
		else
			sprintf(line, "Invalid");
		write(STDOUT_FILENO, line, strlen(line));
	}
	return 0;
}