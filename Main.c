// this is for file io and stuff
#include <stdio.h>
// this is for malloc
#include <stdlib.h>

// a simple implementation of cat
int main(int argc, char** args)
{
	if( argc == 1) // handles a base case problem of none
	{
		for( int i = 0 ; i < argc ; i++)
			puts(args[i]);
		return 0 ; 
	}
	
	// this is the actual stuff
	FILE* f = fopen(args[1], "r");
	fseek(f, 0, SEEK_END);
	int siz = ftell(f);
	fseek(f, 0, SEEK_SET);

	// this is the main loop
	char c = 0 ; 
	for( int i = 0 ; i < siz ; i++)
	{
		c = fgetc(f);
		printf("%c",c);
	}
	fclose(f);
	return 0 ;
}
