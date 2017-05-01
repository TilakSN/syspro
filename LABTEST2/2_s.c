#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#define MAX 80

int main(){
	char b[MAX];
	int in, out, n;
	mkfifo("server_to_client", 0777);
	mkfifo("client_to_server", 0777);
	while(1){
		in = open("client_to_server", O_RDWR, 0777);
		out = open("server_to_client", O_RDWR, 0777);
		memset(b, 0, MAX);
		printf("Waiting for MSG\n");
		n = read(in, b, MAX);
		printf("MSG: %s\n", b);
		b[0] = toupper(b[0]);
		printf("Sending Reply\n");
		write(out, b, n);
		close(in);
		close(out);
	}
	return 0;
}