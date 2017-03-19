/******************************/
/* Illustrate chmod and umask */
/*                            */
/*    Author: Tilak S Naik    */
/******************************/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#define B_SIZE 4096

int main() {
    int file;
    printf("Creating file with mode = 777\n");
    if ((file = open("file_1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    close(file);
    printf("Setting umask to 666\n");
    // pass ~0666 = 0111
    int old_mask = umask(0111); // prefix 0 for octal values
    printf("Creating file with mode = 777\n");
    if ((file = open("file_2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    close(file);
    printf("Creating file with mode = 777\n");
    if ((file = open("file_3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }
    close(file);
    printf("Changing mode of file_3\n");
    if (chmod("file_3.txt", 0333) == -1)
        printf("Error changing mode\n");
    else
        printf("Mode changed successfully\n");
    umask(old_mask);  // undo changes for future use
    // ls -la will list the modes of all files, use it to show results
    // note that permissions of all files created inside a folder does not get more permissions (except if you use chmod)
    return 0;
}