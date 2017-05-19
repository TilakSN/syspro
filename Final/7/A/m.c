#include <stdio.h>
#include <pwd.h>

int main() {
	char username[256];
	printf("Enter username: ");
	scanf("%s", username);
	struct passwd *p;
	if (p = getpwnam(username)) {
		printf("Username  : %s\n", p->pw_name);
		printf("Shell     : %s\n", p->pw_shell);
		printf("UID       : %d\n", p->pw_uid);
		printf("GID       : %d\n", p->pw_gid);
	}
	else
		printf("User does not exist\n");
	return 0;
}