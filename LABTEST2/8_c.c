#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SIZE 128

int main(){
	key_t key;
	char *shm, *bu;
	int shmid, n;
	key = 1234;
	shmid = shmget(key, SIZE, 0777);
	shm = shmat(shmid, NULL, 0);
	for(bu = shm; *bu != 0; bu++)
		printf("%c\n", *bu);
	*shm = '*';
	return 0;
}