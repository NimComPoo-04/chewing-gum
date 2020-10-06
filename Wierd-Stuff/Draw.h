#include <stdio.h>

#define DRAW_BLACK	(30)
#define DRAW_RED	(31)
#define DRAW_GREEN	(32)
#define DRAW_YELLOW	(33)
#define DRAW_BLUE	(34)
#define DRAW_MAGENTA	(35)
#define DRAW_CYAN	(36)
#define DRAW_WHITE	(37)

#define DRAW_FOREGROUND (0)
#define DRAW_BACKGROUND (10)

#define DRAW_RESET	(0)

struct Pixel
{
	int posx ; 
	int posy ; 
	char type ; 
	int color ; 
};

int Draw_PutChar(struct Pixel* pix) ;
/* this method uses the pixel struct's posx and posy as width and height */
int Draw_InitF(struct Pixel* pix) ;

int Draw_Line( struct Pixel pix[2]) ; 
int Draw_Square( struct Pixel pix[4]) ;
int Draw_Circle( struct Pixel* pix, int rad) ; 

int Draw_DeinitF() ;
int Draw_Clear() ; 
