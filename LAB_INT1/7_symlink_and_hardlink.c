/********************************************/
/* Contents of soft / symlink and hard link */
/*                                          */
/*           Author: Tilak S Naik           */
/********************************************/

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#define B_SIZE 4096

int main() {
    int choice;
    char f_old[B_SIZE], f_new[B_SIZE], buffer[B_SIZE] = {};
    printf("Enter old and new paths:\n");
    scanf("%s%s", f_old, f_new);
    printf("Press 1 for symlink, any other key for hard link\n");
    scanf("%d", &choice);
    if (choice == 1) {
        if (symlink(f_old, f_new) != 0) {
            printf("Error linking\n");
            return -1;
        }
        if (readlink(f_new, buffer, B_SIZE) < 0) {
            printf("Error reading link\n");
            return -1;
        }
        printf("Symlink '%s' contains '%s'\n", f_new, buffer);
    }
    else {
        if (link(f_old, f_new) != 0) {
            printf("Error linking\n");
            return -1;
        }
    }
    struct stat old, new;
    if (stat(f_old, &old) != 0 || stat(f_new, &new)) {
        printf("Error retrieving stat\n");
        return -1;
    }
    printf("Old inode: %lu\nNew inode: %lu\nNumber of links: %lu\n", old.st_ino, new.st_ino, old.st_nlink);
    return 0;
}


/*$ touch b1
$ echo "Cat">b1
$ ./a.out b1 b2 b3
    soft link created
$ ls -li b1 b2
    ls: cannot access b2: No such file or directory
    3155469 -rw-rw-r-- 1 guest1 guest1 4 Mar 13 09:37 b1
$ ls -li b1 b3
    3155469 -rw-rw-r-- 1 guest1 guest1 4 Mar 13 09:37 b1
    3156073 lrwxrwxrwx 1 guest1 guest1 2 Mar 13 09:37 b3 -> b2
$ ./a.out b1 b2
    b1 b2hard link created
$ ls -li b1 b3
    3155469 -rw-rw-r-- 2 guest1 guest1 4 Mar 13 09:37 b1
    3156073 lrwxrwxrwx 1 guest1 guest1 2 Mar 13 09:37 b3 -> b2
$ ls -li b1 b2
    3155469 -rw-rw-r-- 2 guest1 guest1 4 Mar 13 09:37 b1
    3155469 -rw-rw-r-- 2 guest1 guest1 4 Mar 13 09:37 b2
$ ls -li b2 b3
    3155469 -rw-rw-r-- 2 guest1 guest1 4 Mar 13 09:37 b2
    3156073 lrwxrwxrwx 1 guest1 guest1 2 Mar 13 09:37 b3 -> b2

*/
