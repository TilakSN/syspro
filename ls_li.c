/******************************************/
/* Emulate ls -li and remove empty files  */
/*                                        */
/*          Author: Tilak S Naik          */
/******************************************/

#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#define B_SIZE 4096

int main() {
    DIR *d = opendir(".");
    struct dirent *entry;
    struct stat f;
    while ((entry = readdir(d)) != NULL) {
        printf("\nFile name: %s\n", entry->d_name);
        if (stat(entry->d_name, &f) < 0) {
            printf("Error reading stat\n");
            continue;
        }
        printf("Inode: %lu\nMode: %o\nLinks: %lu\nUID: %u\nGID: %u\nSize: %ld\nChange time: %s", f.st_ino, f.st_mode, f.st_nlink, f.st_uid, f.st_gid, f.st_size, ctime(&f.st_ctime));
        if (f.st_size == 0) {
            printf("Blank file... ");
            if (remove(entry->d_name) == 0)
                printf("Deleted\n");
            else
                printf("Delete failed\n");
        }
    }
    return 0;
}
