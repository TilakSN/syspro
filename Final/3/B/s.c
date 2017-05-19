#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
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
	if ((md = msgget(key, IPC_CREAT | 0666)) < 0)
		_err("Creating message queue");
	msgrcv(md, &buf, 256, buf.type, 0);
	if ((fd = open(buf.text, O_RDONLY)) < 0)
		_err("Opening file");
	if ((n = read(fd, buf.text, 256)) < 0)
		_err("Reading file");
	buf.type = 2;
	msgsnd(md, &buf, n, 0);
	return 0;
}