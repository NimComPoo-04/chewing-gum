#include "Draw.h"
#include <stdio.h>

typedef struct Pixel Pixel ; 

int main( void )
{
	Pixel background = {60,20,' ',DRAW_RED + DRAW_BACKGROUND} ;
	Draw_InitF(&background);
	for( int i = 1 ; i < 10 ; i++)
	{
		Pixel fore = {i,0,'&',DRAW_CYAN} ;
		Draw_PutChar(&fore);
	}
	Draw_DeinitF();
}
