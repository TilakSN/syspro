#include <setjmp.h>
#include <stdio.h>

jmp_buf stack_trace;

void foo() {
	printf("In function...\n");
	printf("Calling longjmp...\n");
	longjmp(stack_trace, 1);
	printf("This won't be printed...\n");
}

int main() {
	printf("Starting the program...\n");
	if (setjmp(stack_trace)) {
		printf("Inside setjmp...\n");
	}
	else {
		printf("Calling function...\n");
		foo();
	}
	printf("Done...\n");
	return 0;
}