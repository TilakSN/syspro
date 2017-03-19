#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int input_file = open("input.txt", O_RDWR);
    if (input_file == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    int copy;
    printf("File descriptor of the opened file: %d\n", input_file);
    printf("Enter the required file descriptor: ");
    scanf("%d", &copy);
    copy = dup2(input_file, copy);
    // uses the FD passed. If already open, closes it before reuse
    printf("New file descriptor after dup2() call: %d\n", copy);
    close(input_file);
    return 0;
}