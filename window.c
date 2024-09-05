#include <SDL2/SDL.h>

int main(void)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	

	/* Initializing SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to Initialized SDL: %s\n", SDL_GetError());
		return (1);
	}

	/* Creating a new window */
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
	}
	return (0);
}
