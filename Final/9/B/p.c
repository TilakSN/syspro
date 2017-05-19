#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;
	printf("Argument parser:\n");
	for (i = -1; ++i < argc;)
		printf("Arg %d: %s\n", i, argv[i]);
	return 0;
}