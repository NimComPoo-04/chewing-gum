#include "Draw.h"

static int draw_height ; 
static int draw_width ;

int Draw_InitF(struct Pixel* pix)
{
	printf("\033[0H\033[0J");
	for( int i = 0 ; i < pix->posy ; i++)
	{
		for( int j = 0 ; j < pix->posx ; j++)
		{
			printf("\033[%dm%c", pix->color, pix->type) ; 
		}
		puts("") ; 
	}
	
	draw_height = pix->posy ; 
	draw_width = pix->posx ; 

	return 0 ; 
}

int Draw_PutChar(struct Pixel* pix)
{
	printf("\033[%d;%dH\033[%dm%c",pix->posy+1,pix->posx+1,pix->color,pix->type) ; 
	return 0 ; 
}

int Draw_DeinitF()
{
	printf("\033[%d;0H\033[0m",draw_height+1);
	return 0;
}

int Draw_Clear()
{
	printf("\033[0H\033[0J");
}
