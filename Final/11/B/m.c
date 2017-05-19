#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 5

sem_t resource_lock;
sem_t read_lock;
sem_t write_lock;

int R, W;

void *reader(void *arg) {
	int i, n = (int) (long) arg;
	printf("Reader %d is starting\n", n);
	for (i = -1; ++i < MAX;) {
		sleep(1);
		sem_wait(&read_lock);
		sem_wait(&resource_lock);
		printf("Reader %d got %d\n", n, R++);
		sem_post(&read_lock);
	}
	return NULL;
}

void *writer(void *arg) {
	int i, n = (int) (long) arg;
	printf("Writer %d is starting\n", n);
	for (i = -1; ++i < MAX;) {
		sleep(1);
		sem_wait(&write_lock);
		printf("Writer %d put %d\n", n, W++);
		sem_post(&resource_lock);
		sem_post(&write_lock);
	}
	return NULL;
}

int main() {
	sem_init(&resource_lock, 0, 0);
	sem_init(&read_lock, 0, 1);
	sem_init(&write_lock, 0, 1);

	int n, i;
	printf("Enter number of readers/writers: ");
	scanf("%d", &n);

	pthread_t readers[n], writers[n];

	for (i = -1; ++i < n;) {
		pthread_create(readers + i, 0, reader, (void *) (long) (i + 1));
		pthread_create(writers + i, 0, writer, (void *) (long) (i + 1));
	}

	for (i = -1; ++i < n;) {
		pthread_join(readers[i], (void **) NULL);
		pthread_join(writers[i], (void **) NULL);
	}
	return 0;
}