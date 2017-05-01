#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main( int argc, char* *argv )
{
	struct passwd* pw;
	int i, n = 3; // three users
	for(i = 1;i<=n;i++)
	{
	    	if( ( pw = getpwnam( argv[i] ) ) == NULL ) 
		{
			fprintf( stderr, "getpwnam: unknown %s\n",argv[1] );
	      		return( EXIT_FAILURE );
	    	}

	    	printf( "Login Name  %s\n", pw->pw_name );
	    	printf( "User ID     %d\n", pw->pw_uid );
	    	printf( "Group ID    %d\n", pw->pw_gid );
	    	printf( "Home DIR    %s\n", pw->pw_dir );
	    	printf( "Login Shell %s\n", pw->pw_shell );
		printf(" ------------------------------------\n");
	}
    	return( EXIT_SUCCESS );
  }
