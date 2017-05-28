/******************************************************/
/* Read 100B from file and write 50B each to 2 files  */
/*                                                    */
/*                Author: Tilak S Naik                */
/******************************************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define B_SIZE 4096

int main() {
    int input_file = open("input.txt", O_RDONLY);
    int output_file_1 = open("t1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int output_file_2 = open("t2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (input_file == -1 || output_file_1 == -1 || output_file_2 == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    char buffer[B_SIZE];
    int read_count = read(input_file, buffer, 50);
    int write_count = write(output_file_1, buffer, read_count);
    if (write_count != read_count) {
        fprintf(stderr, "Write error 1\n");
        return -1;
    }
    read_count = read(input_file, buffer, 50);
    write_count = write(output_file_2, buffer, read_count);
    if (write_count != read_count) {
        fprintf(stderr, "Write error 2\n");
        return -1;
    }
    close(input_file);
    close(output_file_1);
    close(output_file_2);
    return 0;
}