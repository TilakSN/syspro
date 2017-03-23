/******************************************/
/* List the details of file using (l)stat */
/*                                        */
/*          Author: Tilak S Naik          */
/******************************************/

#include <time.h>
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
    // using lstat would also be the same except when used on symbolic link
    // stat on symbolc link returns details of file it points to, but lstat returns details of link itdelf
        printf("Error reading stat\n");
        return -1;
    }
    printf("Device                          : %lu\n", f.st_dev);
    printf("File serial number              : %lu\n", f.st_ino);
    printf("File mode                       : %u\n", f.st_mode);
    printf("Link count                      : %lu\n", f.st_nlink);
    printf("User ID of the file's owner     : %u\n", f.st_uid);
    printf("Group ID of the file's group    : %u\n", f.st_gid);
    printf("Device number, if device        : %lu\n", f.st_rdev);
    printf("Size of file, in bytes          : %ld\n", f.st_size);
    printf("Optimal block size for I/O      : %ld\n", f.st_blksize);
    printf("Number 512-byte blocks allocated: %ld\n", f.st_blocks);
    printf("Time of last access             : %s", ctime(&f.st_atime));
    printf("Time of last modification       : %s", ctime(&f.st_mtime));
    printf("Time of last status change      : %s", ctime(&f.st_ctime));
    return 0;
}
