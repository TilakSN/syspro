#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

#define SIZE 128

int main(){
	key_t key;
	char *shm, *bu = "abcdefghijklmnopqrstuvwxyz0";
	int shmid, n;
	key = 1234;
	shmid = shmget(key, SIZE, IPC_CREAT|0777);
	shm = shmat(shmid, NULL, 0);
	n = strlen(bu);
	memcpy(shm, bu, n);
	while(*shm != '*')
		sleep(1);
	return 0;
}