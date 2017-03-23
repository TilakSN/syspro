/****************************************/
/* Information from password structure  */
/*                                      */
/*         Author: Tilak S Naik         */
/****************************************/

#include <stdio.h>
#include <pwd.h>
#define B_SIZE 4096

int main() {
    struct passwd *p;
    char name[B_SIZE];
    printf("Enter the username: ");
    scanf("%s", name);
    p = getpwnam(name);
    if (p == NULL) {
        printf("Not found\n");
        return -1;
    }
    printf("Username: %s\nPassword: %s\nUID: %d\nGID: %d\nUser Information: %s\nHome dir: %s\nShell: %s\n", p->pw_name, p->pw_passwd, p->pw_uid, p->pw_gid, p->pw_gecos, p->pw_dir, p->pw_shell);
    // listed in man 3 getpwnam
    return 0;
}
