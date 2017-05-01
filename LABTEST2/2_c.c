#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fnctl.h>
#include <string.h>

#define MAX 80

int main(int argc, char* argv[]){
	char b[MAX];
	int in, out, n;
	in = open("server_to_client", O_RDWR, 0777);
	out = open("client_to_server", O_RDWR, 0777);
	printf("Sending MSG\n");
	n = strlen(argv[1]);
	write(out, argv[1], n);
	read(in, b, MAX);
	printf("MSG Received: %s\n", b);
	close(in);
	close(out);
}