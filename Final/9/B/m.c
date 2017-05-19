#include <stdio.h>
#include <unistd.h>

int main() {
	execl("i", "i", "arg1", "arg2", (char *) NULL);
	return 0;
}