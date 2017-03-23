/********************************************/
/* Print holes in file using lseek function */
/*                                          */
/*           Author: Tilak S Naik           */
/********************************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int output_file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
    if (output_file == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    int len = 5; // strlen("Hello")
    int write_count = write(output_file, "Hello", len);
    if (write_count != len) {
        fprintf(stderr, "Write error 1\n");
        return -1;
    }
    
    int position = lseek(output_file, 0, SEEK_CUR);
    printf("Adding hole at position: %d\n", position);

    lseek(output_file, 10, SEEK_CUR);
    len = 8; // strlen("World!!!")
    write_count = write(output_file, "World!!!", len);
    if (write_count != len) {
        fprintf(stderr, "Write error 2\n");
        return -1;
    }
    // now ls -l output.txt shows length = 23 bytes (including the hole of size 10)
    // opening in gedit will show a warning and also \00 in the gap.
    close(output_file);
    return 0;
}
