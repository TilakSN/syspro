// Normal execution shows 1, 1, 1
// compile with -O flag and only volatile shows 1

#include <stdio.h>
#include <setjmp.h>

int main() {
	jmp_buf context;
	int a = 0;
	register int b = 0;
	volatile int c = 0;

	if (setjmp(context)) {
		printf("Normal  : %d\n", a);
		printf("Register: %d\n", b);
		printf("Volatile: %d\n", c);
		return 0;
	}
	a++;
	b++;
	c++;
	longjmp(context, 1);
}