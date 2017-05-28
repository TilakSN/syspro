#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

void daemonize(){
	pid_t pid = fork();
	if(pid < 0)
		fprintf(stderr, "Error Forking!\n");
	else if(pid){
		printf("PID of child: %d\n", pid);
		exit(0);
	}
	umask(0);
	if(chdir("/") < 0)
		printf("Error changing directory\n");
	if(setsid() < 0)
		printf("Error changing session\n");
	printf("Daemon created \n");
}

int main(){
	daemonize();
	system("ps -axj\n");
	return 0;
}