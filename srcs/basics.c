/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:17:32 by chbelan           #+#    #+#             */
/*   Updated: 2020/02/13 15:20:59 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <SDL2/SDL.h>

int init( SDL_Window** window, SDL_Surface** screenSurface )
{
	if(0 != SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		return -1;
	}
	*window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							   500, 500, SDL_WINDOW_SHOWN);
	if(NULL == *window)
	{
		fprintf(stderr, "Erreur de creation de la fenetre : %s\n", SDL_GetError());
		return -1;
	}
	*screenSurface = SDL_GetWindowSurface(*window);
	return 0; 
}


int main(int argc, char* argv[])
{
	SDL_Window *window = NULL;
	SDL_Surface* screenSurface = NULL;

	init(&window, &screenSurface);

	SDL_Delay(500);

	return 0;
}
