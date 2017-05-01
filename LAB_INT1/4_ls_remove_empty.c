/**************************************/
/* Emulate ls and remove empty files  */
/*                                    */
/*        Author: Tilak S Naik        */
/**************************************/

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
        printf("Entry: %s\n", entry->d_name);
        if (stat(entry->d_name, &f) < 0) {
            printf("Error reading stat\n");
            continue;
        }
        if (f.st_size == 0) {
            printf("Blank file... ");
            if (remove(entry->d_name) == 0)
                printf("Deleted\n");
            else
                printf("Delete failed\n");
        }
    }
    closedir(d);
    return 0;
}