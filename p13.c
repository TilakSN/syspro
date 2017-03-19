/****************************************/
/* File access permissions using fcntl  */
/*                                      */
/*         Author: Tilak S Naik         */
/****************************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int input_file = open("input.txt", O_RDONLY);
    // change mode to O_WRONLY, O_RDWR, O_WRONLY | O_APPEND etc to get different status values
    // man fcntl has a section File status flags that describes this
    if (input_file == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    int status = fcntl(input_file, F_GETFL);
    close(input_file);
    printf("Status: %o\n", status);
    return 0;
}