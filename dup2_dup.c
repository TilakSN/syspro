/**********************************/
/* Advantage of dup2() over dup() */
/*                                */
/*      Author: Tilak S Naik      */
/**********************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int input_file = open("input.txt", O_RDWR);
    if (input_file == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    printf("File descriptor of the opened file: %d\n", input_file);
    int copy = dup(input_file);
    // Uses the least unused FD
    printf("New file descriptor after dup() call: %d\n", copy);
    printf("Enter the required file descriptor: ");
    scanf("%d", &copy);
    copy = dup2(input_file, copy);
    // uses the FD passed. If already open, closes it before reuse
    printf("New file descriptor after dup2() call: %d\n", copy);
    close(input_file);
    return 0;
}
