/********************************************/
/* Race between parent and child processes  */
/*                                          */
/*           Author: Tilak S Naik           */
/********************************************/

#include <unistd.h>
#include <stdio.h>
#define B_SIZE 4096

int main() {
    int pid = fork();
    if (pid == 0) {
        // Parent
        int i;
        for (i = 0; i < 50; i += 2)
            printf("%d\n", i);
    }
    else if (pid > 0) {
        // child
        int i;
        for (i = 1; i < 50; i += 2)
            printf("%d\n", i);
    }
    return 0;
}
