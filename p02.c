/**************************************/
/* Read from file and write to STDOUT */
/*                                    */
/*        Author: Tilak S Naik        */
/**************************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define B_SIZE 4096

int main() {
    int input_file = open("input.txt", O_RDONLY);
    if (input_file == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    char buffer[B_SIZE];
    int read_count = read(input_file, buffer, B_SIZE);
    int write_count = write(STDOUT_FILENO, buffer, read_count);
    if (write_count != read_count) {
        fprintf(stderr, "Write error\n");
        return -1;
    }
    return 0;
}