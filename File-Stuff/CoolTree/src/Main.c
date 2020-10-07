#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

#define DRAW_BLACK	(30)
#define DRAW_RED	(31)
#define DRAW_GREEN	(32)
#define DRAW_YELLOW	(33)
#define DRAW_BLUE	(34)
#define DRAW_MAGENTA	(35)
#define DRAW_CYAN	(36)
#define DRAW_WHITE	(37)

#define DRAW_BRIGHT	(60)
#define DRAW_BACKGROUND (10)

// Lets make a visualizer
// so we will visualize the directory tree

/*
 * this program will list all the files in a directory recursively
 * it will print their name. It is irritatingly inferior to ls in linux
 * system but really what do you except :-)
 */

void PrintDir(char *d, int len);
void EmptySpace(char *c, int len);
void DesignPrinter(struct dirent* us, int len);

/* this function will intiate the process */
int main(int a, char** c)
{
	if(a == 1)
		PrintDir(".", 2);
	else
	{
		chdir(c[1]);
		PrintDir('.', 2);
	}
	puts("") ;
}

/* this is the replacement for memset */
void EmptySpace(char* c, int len)
{
	if( len == 0) return ;
	for( int i =0  ;i< len ;i++) c[i] = '|' ;
	c[len-1] = '\0' ; 
}

/* this is the main recursive method */
void PrintDir(char* c, int len)
{
	DIR *d = opendir(c) ;
	if( d == NULL)
	{
		puts("\033[31m<DIR ! EXISTS>\033[0m") ;
		return ;
	}
	struct dirent* usri ; 
	while(1)
	{
		usri = readdir(d);
		if( usri == NULL ) break;

		if( usri->d_name[0] == '.' ) continue ; 
	
		DesignPrinter(usri, len) ; 

		if( usri->d_type == 4)
		{
			chdir(usri->d_name);
			PrintDir(".",len+1) ;
			chdir("..");
		}
	} 
	closedir(d);
}

void DesignPrinter(struct dirent* us, int len)
{
	char* c = us->d_name ; 
	int d = us->d_type ; 

	char* spaces = malloc(len*sizeof(char)) ; 
	EmptySpace(spaces, len) ;
       	printf("%s",spaces) ;
	char* ck ; // gets the funny things in life
	
	switch(d)
	{
		case 4 : 
			printf("\n%s\033[%dm < DIR > ",spaces,DRAW_BRIGHT+DRAW_YELLOW) ; 
		break ;
		case 8:
			if( strstr(c,".c") )
				printf("\033[%dm( BESTY )",DRAW_RED+DRAW_BRIGHT);			
			else if( (ck = strstr(c,".")) )
				printf("\033[%dm( TYPE : %s )",DRAW_CYAN+DRAW_BRIGHT,ck+1);
			else
				printf("\033[%dm\033[%dm",DRAW_BLACK,DRAW_WHITE+DRAW_BACKGROUND) ;
			printf("->") ;
		break ;
	}
	printf("%s\033[0m\n",c) ; 
}
