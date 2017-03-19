/******************************************/
/* Changing access and modification times */
/*                                        */
/*          Author: Tilak S Naik          */
/******************************************/

#include <time.h>
#include <utime.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#define B_SIZE 4096

int main() {
    struct stat f;
    char buffer[B_SIZE];
    printf("Enter file name: ");
    scanf("%s", buffer);
    if (stat(buffer, &f) < 0) {
        printf("Error reading stat\n");
        return -1;
    }
    printf("Before update:\n");
    printf("Time of last access       : %s", ctime(&f.st_atime));
    printf("Time of last modification : %s", ctime(&f.st_mtime));
    printf("Time of last status change: %s", ctime(&f.st_ctime));
    struct utimbuf t;
    t.actime = time(NULL) - 300;
    t.modtime = time(NULL) - 500;
    utime(buffer, &t);
    if (stat(buffer, &f) < 0) {
        printf("Error reading stat\n");
        return -1;
    }
    printf("After update:\n");
    printf("Time of last access       : %s", ctime(&f.st_atime));
    printf("Time of last modification : %s", ctime(&f.st_mtime));
    printf("Time of last status change: %s", ctime(&f.st_ctime));
    return 0;
}
