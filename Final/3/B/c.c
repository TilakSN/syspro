#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void _err(char *msg) {
	fprintf(stderr, "Error: %s.\n", msg);
	exit(EXIT_FAILURE);
}

typedef struct msgbuf {
	long type;
	char text[256];
}msgbuf;

int main() {
	int md, fd, n;
	msgbuf buf;
	key_t key = 1048;
	buf.type = 1;
	if ((md = msgget(key, 0666)) < 0)
		_err("Getting message queue");
	printf("Enter filename: ");
	scanf("%s", buf.text);
	n = strlen(buf.text);
	msgsnd(md, &buf, n, 0);
	buf.type = 2;
	msgrcv(md, &buf, 256, buf.type, 0);
	printf("Contents received: %s\n", buf.text);
	return 0;
}