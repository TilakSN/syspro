#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
	pid_t pid;
	if((pid = fork())<0)
		printf("Error\n");
	else if(pid == 0)
		if(execl("interpreter", "test", "myarg1", "myarg2", "myarf4", (char*)0)<0)
			printf("Error1\n");
	if(waitpid(pid, NULL, 0) < 0)
		printf("Wait error\n");
	system("ls> list");
	return 0;
}