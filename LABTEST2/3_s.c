#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>
#include <fcntl.h>

#define SIZE 128

typedef struct msgbuf{
	long mbyte;
	char mtext[SIZE];
}msgbuf;

int main(int argc, char* argv[]){
	int msgid, n, fd;
	key_t key;
	char text[SIZE];
	msgbuf b;
	key = 1234;
	msgid = msgget(key, IPC_CREAT|0777);
	b.mtype = 1;
	msgrcv(msgid, &b, SIZE, 1, 0);
	fd = open(b.mtext, O_RDWR, 0777);
	n = read(fd, text, SIZE);
	write(STDOUT_FILENO, text, n);
}