#include <stdio.h>
#include <stdlib.h>

void a() {
	printf("Handler a\n");
}

void b() {
	printf("Handler b\n");
}

void c() {
	printf("Handler c\n");
}

int main() {
	atexit(a);
	atexit(b);
	atexit(c);
	printf("Registered handlers.\n");
	return 0;
}