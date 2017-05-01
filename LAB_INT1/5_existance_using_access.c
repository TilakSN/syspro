/********************************************/
/* Check existence of a file using access() */
/*                                          */
/*           Author: Tilak S Naik           */
/********************************************/

#include <unistd.h>
#include <stdio.h>
#define B_SIZE 4096

int main() {
    char buffer[B_SIZE];
    printf("Enter the name of the file: ");
    scanf("%s", buffer);
    if (access(buffer, F_OK) == -1)
        printf("File does not exist\n");
    else
        printf("File exists\n");
    return 0;
}