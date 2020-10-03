#include <stdio.h>
#include <dirent.h>

int main(int len, char** args)
{
	DIR* dir = opendir(args[1]) ;
	if( dir == NULL)
	{
		printf("Nope") ;
		return 1 ;	
	}
       	
	struct dirent* di ; 
	int i = 1 ;
	while( (di = readdir(dir)) )
	{
		if( di->d_type == 4) continue ;
		printf("%d: %s\n", i, di->d_name); 
		i++ ; 
	}

	closedir(dir) ;
}
