/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:43:30 by chbelan           #+#    #+#             */
/*   Updated: 2020/02/12 15:36:42 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int				main(int argc, char **argv)
{
	SDL_Window	*window;
	SDL_version	version;
	
	window = NULL;
	SDL_VERSION(&version);
	printf("You are in the %d.%d.%d SDL version", version.major,
			version.minor, version.patch);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("Error could not set the version %s\n", SDL_GetError());
		exit(-1);
	}
	window = SDL_CreateWindow("Tchadingo RT", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	if (window == NULL)
	{
		SDL_Log("Error could not create Window %s\n", SDL_GetError());
		exit(-1);
	}
	SDL_Delay(7000);
//	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
