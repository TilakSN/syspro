/************************/
/*     Type of file     */
/*                      */
/* Author: Tilak S Naik */
/************************/

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#define B_SIZE 4096

int main() {
    char buffer[B_SIZE];
    printf("Enter the name of the file: ");
    scanf("%s", buffer);
    struct stat f;
    if (stat(buffer, &f) < 0)
        return -1;
    unsigned int mode = f.st_mode;
    unsigned int type = mode & S_IFMT; // S_IFMT is bitmask to extract type
    printf("File type (octal) is: %o\n", type);
    // there are more functions in stat.h that can help you detect each type separately
    // search for stat.h in computer (root) and look for macros
    // or type man 2 stat in terminal
    return 0;
}