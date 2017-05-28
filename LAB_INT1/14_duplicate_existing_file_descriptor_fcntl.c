/******************************************/
/* Duplicate file descriptor using fcntl  */
/*                                        */
/*          Author: Tilak S Naik          */
/******************************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int input_file = open("input.txt", O_RDWR | O_CREAT, 0777);
    if (input_file == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    printf("File descriptor of the opened file: %d\n", input_file);
    printf("Enter the new file descriptor: ");
    int f;
    scanf("%d", &f);
    int copy = fcntl(input_file, F_DUPFD, f);
    // Uses the least unused FD greater than or equal to f
    // try giving 0, 1 or 2 as 3rd arg to see the difference
    printf("New file descriptor after duplication: %d\n", copy);
    close(input_file);
    return 0;
}