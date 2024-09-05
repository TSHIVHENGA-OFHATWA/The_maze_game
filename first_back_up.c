#include <SDL2/SDL.h>
#include <stdio.h>
#include "constant.h"

int game_run = FALSE;
SDL_Window *window = NULL;
SDL_Renderer *renderer;

int Initilze_window(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Unable to Initialized SDL: %s\n", SDL_GetError());
		return (FALSE);
	}

	window = SDL_CreateWindow("The Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, 0);

	if (window == NULL)
	{
		fprintf(stderr, "SDL Create window err: %s\n", SDL_GetError());
		SDL_Quit();
		return (FALSE);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		fprintf(stderr, "SDL CreateRender err: %s\n", SDL_GetError());
		SDL_Quit();
		return (FALSE);
	}
	return (TRUE);
}
void process_input()
{

}

void update()
{

}


void render()
{

}

int main(void)
{
	/*SDL_Window *window;
	SDL_Renderer *renderer;*/
	


	/* Creating a new window 
	window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, 0);

	if (window == NULL)
	{
		fprintf(stderr, "SDL Create window err: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		fprintf(stderr, "SDL CreateRender err: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}*/
	game_run = Initiate Windows();

	setup();

	while (game_run)
	{
		process_input();
		Update();
		render();
	}
	return (0);
}
