#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 128

int main(){
	FILE *fp;
	char b[MAX];
	mknod("channel", S_IFIFO|0777, 0);
	while(1){
		fp = fopen("channel", "r");
		fgets(b, MAX, fp);
		printf("MSG Received: %s\n", b);
		fclose(fp);
	}
	return 0;
}