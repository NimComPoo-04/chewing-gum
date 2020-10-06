#include "Draw.h"
#include <stdio.h>

typedef struct Pixel Pixel ; 

int main( void )
{
	Pixel background = {60,20,' ',DRAW_RED + DRAW_BACKGROUND} ;
	Draw_InitF(&background);

	Pixel p[2] = {(Pixel){2,2,'*',DRAW_BLUE},(Pixel){10,2,' ',0}} ; 
	Draw_Line(p) ; 
	
	Draw_DeinitF();
}
