#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char* argv[]){
	struct passwd *pw;
	if(pw = getpwnam(argv[1])){
		printf("Login name: %s\n", pw->pw_name);
		printf("Shell: %s\n", pw->pw_shell);
		printf("UID: %s\n", pw->pw_uid);
		printf("GID: %s\n", pw->pw_gid);
	}
	else
		printf("User %s doesn't exist!\n", argv[1]);
}