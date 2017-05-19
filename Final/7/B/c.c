#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	int sd, i;
	char *shm;
	key_t key = 1048;
	sd = shmget(key, 256, 0666);
	shm = shmat(sd, NULL, 0);
	printf("Reading from shared memory...\nContents:\n");
	// for (int i = -1; ++i < 26;)
	// 	printf("%c", shm[i]);
	printf("%s\n", shm);
	printf("Acknowledging...\n");
	shm[100] = 0;
	printf("Exiting...\n");
	return 0;
}