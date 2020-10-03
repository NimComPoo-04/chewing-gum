#include <stdio.h>
#include <string.h> // this uses strcmp

int Clip_Puts(const char* from, const char* to) ; 

int main(int argc, char** args)
{
	if( argc < 3 ) return 1 ;

	if( args[1][0] == 'c' )
	{
		Clip_Puts(args[2], "clipstuff") ;
	}

	else if( args[1][0] == 'p' )
	{
	
		Clip_Puts("clipstuff", args[2]) ; 
	}
}

int Clip_Puts(const char* from, const char* to)
{
	// FILE is opened to __
	FILE *fr = fopen(from, "r") ; 
	FILE *fw = fopen(to, "w") ; 
	
	// A bit of err checking 
	if( fr == NULL || fw == NULL )
		return 1 ; 

	// Copies the :--:
	char c = 0 ;
	
	// gets the len of the file
	fseek(fr, 0, SEEK_END) ;
	int len = ftell(fr);
	fseek(fr,0,SEEK_SET) ; 

	// writes to the file
	for( int i = 0 ; i < len ; i++)
	{
		 c = fgetc(fr);
		 fputc(c, fw) ; 
	}

	// frees the resources
	fclose(fr) ; 
	fclose(fw) ;

	return 0 ; 
}
