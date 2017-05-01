#include <stdio.h>
#include <setjmp.h>

jmp_buf jmp;

int divide(int a, int b){
	if(b == 0)
		longjmp(jmp, 1);
	else
		return a/b;
}

int main(int argc, char* argv[]){
	int ans, a = atoi(argv[1]), b = atoi(argv[2]);
	if(setjmp(jmp) == 0){
		ans = divide(a, b);
		printf("Quotient: %d\n", ans);
	}
	else
		printf("Divide by zero exception caught!\n");
	return 0;
}