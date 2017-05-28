#include <stdio.h>
#include <unistd.h>

void handler_1(){
	printf("Exit Handler1\n");
}

void handler_2(){
	printf("Exit Handler2\n");
}

int main(){
	atexit(handler_1);
	atexit(handler_2);
	printf("Calling implicit exit()\n");
	return 0;
}