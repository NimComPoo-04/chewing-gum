#include <stdio.h>

#define M_CON_HEIGHT 10
#define M_CON_WIDTH 30

int InitField(void) ; 
int DrawField(int,int,int) ;
int DeInitField(void) ; 

int main( void )
{
	InitField() ; 	
	DrawField(6,2,32) ; 
	DrawField(7,2,33) ; 
	DrawField(8,2,34) ; 
	DrawField(9,2,35) ; 
	DeInitField() ;
}

// This is the method which inits the field
int InitField(void)
{
	printf("\033[H\033[J");
	printf("\033[1m") ;
	for( int i = 0 ; i < M_CON_HEIGHT ; i++)
	{
		for( int j = 0 ; j < M_CON_WIDTH ; j++)
		{
			printf(" ") ; 
		}
		puts("") ; 
	}

	return 0 ; 
}

// This is the method which draws field
int DrawField(int x, int y, int co)
{
	printf("\033[%d;%dH", y+1, x+1) ; 
	printf("\033[%dm*",co) ; 
}

int DeInitField(void)
{
	printf("\033[%d;0H",M_CON_HEIGHT) ; 
	printf("\033[0m") ;
}
