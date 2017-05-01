#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>

#define SIZE 128

typedef struct msgbuf{
	long mytype;
	char mtext[SIZE];
}msgbuf;

int main(int argc, char* argv[]){
	int msgid;
	key_t key;
	struct msgbuf b;
	key = 1234;
	msgid = msgget(key, 0777);
	b.mtype = 1;
	strcpy(b.mtext, argv[1]);
	msgsnd(msgid, &b, strlen(srgv[1]), IPC_NOWAIT);
}