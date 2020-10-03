#include <stdio.h>
#include <stdlib.h>

void DrawCircle(int) ; 

int main(int ar, char** as)
{
	int data = atoi(as[1]) ; 
	
	DrawCircle(data) ; 	
}

void DrawCircle( int r )
{
	r/=2 ;
	for( int i = -r ; i < r ; i++)
	{
		for( int j = -r ; j < r ; j++)
		{
			if( i*i + j*j < r*r)
				printf("* ") ;	
			else
				printf("  ") ;
		}
		puts(" ") ; 
	}
}
