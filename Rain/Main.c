#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#define FPS (60)

/* This requires sdl because I don't really want to do system specific stuff because it is harder and not portable 
 * SDL:- www.libsdl.org */

void HandleEvent(SDL_Event* eve) ; 
SDL_Color getRandomColor(void) ; 

int isPlaying = 1 ; 
typedef struct 
{
	SDL_Rect draw ; 
	int vel ; 
	SDL_Color color ; 
} VioletMyLove;

int main(void)
{
	SDL_Window* win ; 
	SDL_Renderer* ren ; 
	SDL_Event eve ; 
	
	VioletMyLove* raindrop = (VioletMyLove*)malloc(sizeof(VioletMyLove) * 50); 
	for( int i = 0 ; i < 50 ; i++ )
	{
		raindrop[i].draw = (SDL_Rect){i*10,rand()%500+1,9,50} ; 
		raindrop[i].vel = rand()%5+5; 
		if( raindrop[i].vel < 8 )
			raindrop[i].draw.h=60 ; 
		else 
			raindrop[i].draw.h=40 ; 
		raindrop[i].color = getRandomColor(); 
	}

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) ; 
	
	win = SDL_CreateWindow("Purple Rain!!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_RENDERER_ACCELERATED) ; 
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED) ; 
	while(isPlaying)
	{
		Uint32 ct = SDL_GetTicks() ; 
		
		HandleEvent(&eve) ;  
		
		// Paints the background	
		SDL_SetRenderDrawColor(ren, 230, 230, 255, 255) ; 	
		SDL_RenderClear(ren) ; 
		// Paint one Rain
		for( int i = 0 ; i < 50 ; i++ )
		{
			SDL_SetRenderDrawColor(ren, raindrop[i].color.r, raindrop[i].color.g, raindrop[i].color.b, 255) ; 
			SDL_RenderFillRect(ren, &(raindrop[i].draw)) ; 

			if( raindrop[i].draw.y <= 500)
				raindrop[i].draw.y+=raindrop[i].vel ; 
			else 
			{
				raindrop[i].draw.y = -50;
				srand(rand()) ; 
shitman:			raindrop[i].vel = rand()%5+5; 

				if( i != 0 && abs(raindrop[i-1].vel - raindrop[i].vel) < 1 ) 
					goto shitman; 

				if( raindrop[i].vel < 8 )
					raindrop[i].draw.h=60 ; 
				else 
					raindrop[i].draw.h=40 ;
				
				raindrop[i].color = getRandomColor(); 
			}
					}
		SDL_RenderPresent(ren) ; 
		
		while( SDL_GetTicks()-ct < 1000/FPS ) ; 
	}
	
	SDL_DestroyWindow(win) ; 
	SDL_DestroyRenderer(ren) ; 	
	SDL_Quit() ; 
	return 0 ; 
}

void HandleEvent(SDL_Event* eve)
{
	while(SDL_PollEvent(eve))
		if( eve->type == SDL_QUIT )
			isPlaying = 0 ; 
}

SDL_Color getRandomColor(void)
{
	int dat = rand()%4 ; 
	switch(dat)
	{
		case 0: return (SDL_Color){204, 102, 255, 255} ;   
		case 1: return (SDL_Color){255, 102, 255, 255} ;   
		case 2: return (SDL_Color){255, 102, 102, 255} ;   
		case 3: return (SDL_Color){153, 102, 255, 255} ;   
	}	
	return (SDL_Color){0,0,0,0} ; 
}
