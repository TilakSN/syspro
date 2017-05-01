#include<fcntl.h>
#include<stdio.h>
#define size 4096
int main(int arg,char *argv[])
{
        int len;
        char buf[size];
        len=readlink(argv[1],buf,size);
        printf("length %d\n",len);
        printf("Unlinking the file\n");
        if(unlink(argv[1])==0)
                printf("Link removed\n");
        else
                printf("Link not removed\n");
        return 0;
}


/*$ cc unlink.c
$ mkdir c1
$ cd c1
/c1$ mkdir c2
/c1$ cd c2
/c1/c2$ touch file
/c1/c2$ cd ..
/c1$ cd ..
$ ln -s /c1/c2/file myfile
$ ls -li myfile
    3156100 lrwxrwxrwx 1 guest1 guest1 11 Mar 13 10:15 myfile -> /c1/c2/file
$ cd c2
    bash: cd: c2: No such file or directory

ALL WE HAVE IS A LINK TO THE FILE, NOT THE ACTUAL FILE.


$ cc unlink.c
$ ./a.out b1 b2
    length -1
    Unlinking the file
    Link removed


AS OF THIS STEP THE LINK FROM THE PREVIOUS PROGRAM IS REMOVED. SO WHEN WE TRY EXECUTING IT AGAIN..
$ ./a.out b1 b2
length -1
Unlinking the file
Link not removed

HARD LINKS CANNOT BE CREATED TO DIRECTORIES UNLESS WE HAVE SUPERUSER PERMISSIONS
HARDLINKS NORMALLY REQUIRE THAT THE LINK AND THE FILE RESIDE IN THE SAME FILE SYSTEM.
*/
