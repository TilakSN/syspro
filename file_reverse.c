/******************************/
/* Read file in reverse order */
/*                            */
/*    Author: Tilak S Naik    */
/******************************/

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
    int i = lseek(input_file, 0, SEEK_END);
    while (i > 0) {
        read(input_file, buffer, 1);
        lseek(input_file, -2, SEEK_CUR);
        write(STDOUT_FILENO, buffer, 1);
        i--;
    }
    close(input_file);
    return 0;
}
