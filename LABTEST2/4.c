#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX 4

int main(){
	int n, a, b;
	char bu[MAX];
	while(n = read(STDIN_FILENO, bu, MAX)){
		bu[n] = 0;
		sscanf(bu, "%d%d",&a,&b);
		sprintf(bu, "%d", a+b);
		n = strlen(bu);
		write(STDOUT_FILENO, bu, n);
		printf("\n");
	}
	return 0;
}