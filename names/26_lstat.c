#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
 struct stat file_stats;

 if(argc != 2)
  fprintf(stderr, "Usage: fstat FILE...\n"), exit(EXIT_FAILURE);

 if((lstat(argv[1], &file_stats)) == -1) {
  perror("fstat"); 
  return 1;
 }

 printf(" Filename: %s\n", argv[1]);
 printf(" Device: %lld\n",                       file_stats.st_dev);
 printf(" Inode: %ld\n",                         file_stats.st_ino);
 printf(" Protection: %o\n",                     file_stats.st_mode);
 printf(" Number of Hard Links: %d\n",           file_stats.st_nlink);
 printf(" User ID of Owner: %d\n",               file_stats.st_uid);
 printf(" Group ID of owner: %d\n",              file_stats.st_gid);
 printf(" Device type (if inode device): %lld\n",file_stats.st_rdev);
 printf(" Total size, in bytes: %ld\n",          file_stats.st_size);
 printf(" Blocksize for filesystem I/O: %ld\n",  file_stats.st_blksize);
 printf(" Number of blocks allocated: %ld\n",    file_stats.st_blocks);
 printf(" Time of last access: %ld : %s",        file_stats.st_atime, ctime(&file_stats.st_atime));
 printf(" Time of last modification: %ld : %s",  file_stats.st_mtime, ctime(&file_stats.st_mtime));
 printf(" Time of last change: %ld : %s",        file_stats.st_ctime, ctime(&file_stats.st_ctime));

 return 0;
}
