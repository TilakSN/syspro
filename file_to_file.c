/********************************************/
/* Read from file and write to another file */
/*                                          */
/*           Author: Tilak S Naik           */
/********************************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define B_SIZE 4096

int main() {
    int input_file = open("input.txt", O_RDONLY);
    int output_file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
    if (input_file == -1 || output_file == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    char buffer[B_SIZE];
    int read_count = read(input_file, buffer, B_SIZE);
    int write_count = write(output_file, buffer, read_count);
    if (write_count != read_count) {
        fprintf(stderr, "Write error\n");
        return -1;
    }
    close(input_file);
    close(output_file);
    return 0;
}
