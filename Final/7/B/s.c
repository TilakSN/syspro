#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	int sd, i;
	char *shm;
	key_t key = 1048;
	sd = shmget(key, 256, IPC_CREAT | 0666);
	shm = shmat(sd, NULL, 0);
	printf("Writing to shared memory...\n");
	for (int i = -1; ++i < 26;)
		shm[i] = 'a' + i;
	shm[26] = 0;
	shm[100] = 1;
	printf("Waiting for contents to be read...\n");
	while (shm[100]);
	printf("Exiting...\n");
	return 0;
}