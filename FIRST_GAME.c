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

	window = SDL_CreateWindow("The Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

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
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT: 
			game_run = FALSE;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym ==SDLK_ESCAPE)
				game_run = FALSE;
			break;

	}

}

void setup()
{
	NULL;
}

void update()
{
	NULL;
}


void render()
{
	NULL;
}

void destroy_window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
int main(void)
{
	game_run = Initilze_window();

	setup();

	while (game_run)
	{
		process_input();
		update();
		render();
	}

	destroy_window();
	return (0);
}
