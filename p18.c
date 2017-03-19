/**********************************/
/* dup2() for output redirection  */
/*                                */
/*      Author: Tilak S Naik      */
/**********************************/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int output_file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (output_file == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    printf("1. This is printed on screen but 2 is not.\n");
    dup2(output_file, STDOUT_FILENO);
    printf("2. This is printed in file but 1 is not\n");
    return 0;
}