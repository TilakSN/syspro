#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_WRITERS 3
#define NUM_READERS 3

int item_written = 0;
int item_read = 0;

sem_t semaphore_writer;
sem_t semaphore_reader;
sem_t semaphore_item;

void writer(int c){
	sleep(1);
	printf("Locking Writer %d\n", c);
	sem_wait(&semaphore_writer);
	item_written++;
	sem_post(&semaphore_item);
	if(item_written == 1)
		sem_post(&semaphore_reader);
	printf("Writing to new value %d\n", item_written);
	printf("Witer %d unlocking semaphore\n", c);
	sem_post(&semaphore_writer);
}

void reader(int c){
	sleep(1);
	if(item_written == 0)
		printf("Locking Reder %d since no item has been written yet!\n", c);
	if(item_read == item_written){
		printf("No new item available to read! Locking resource till new item written\n");
		sem_wait(&semaphore_item);
	}
	item_read++;
	printf("Reader %d read value: %d\n", c, item_read);
}

void *begin_reader(void *arg){
	while(1)
		reader((int)arg);
}

void *begin_writer(void * arg){
	while(1)
		writer((int)arg);
}

int main(){
	int i;
	pthread_t reader_th[NUM_READERS];
	pthread_t writer_th[NUM_WRITERS];
	sem_init(&semaphore_writer, 0, 1);
	sem_init(&semaphore_item, 0, 1);
	sem_init(&semaphore_reader, 0, 1);
	for(i = -1; ++i < NUM_WRITERS; )
		pthread_create(&writer_th[i], NULL, begin_writer, (void*)i);
	for(i = -1; ++i < NUM_WRITERS; )
		pthread_create(&reader_th[i], NULL, begin_reader, (void*)i);
	for(i = -1; ++i < NUM_READERS; )
		pthread_join(&reader_th[i], NULL);
	for(i = -1; ++i < NUM_WRITERS; )
		pthread_join(&writer_th[i], NULL);
	return 0;
	
}