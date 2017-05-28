/******************************************/
/* Copying times from one file to another */
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
    char file_1[B_SIZE], file_2[B_SIZE];
    printf("Enter source and destination file names:\n");
    scanf("%s%s", file_1, file_2);
    if (stat(file_1, &f) < 0) {
        printf("Error reading stat\n");
        return -1;
    }
    printf("Time:\n");
    printf("Time of last access       : %s", ctime(&f.st_atime));
    printf("Time of last modification : %s", ctime(&f.st_mtime));
    printf("Time of last status change: %s", ctime(&f.st_ctime));
    struct utimbuf t = {f.st_atime, f.st_mtime};
    utime(file_2, &t);
    if (stat(file_2, &f) < 0) {
        printf("Error reading stat\n");
        return -1;
    }
    printf("After copy:\n");
    printf("Time of last access       : %s", ctime(&f.st_atime));
    printf("Time of last modification : %s", ctime(&f.st_mtime));
    printf("Time of last status change: %s", ctime(&f.st_ctime));
    return 0;
}
