/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:49:03 by chbelan           #+#    #+#             */
/*   Updated: 2020/02/13 14:06:56 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include "SDL.h"
#include <stdlib.h>

int					main(int argc, char **argv)
{
	SDL_Window		*window_ptr;
	SDL_Renderer	*renderer_ptr;
	SDL_Event		event;
	int				value;

	value = 0;
	SDL_Init(SDL_INIT_VIDEO);
	window_ptr = SDL_CreateWindow("Tchadingo window",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			1280, 720, SDL_WINDOW_OPENGL);
	if (window_ptr == NULL)
		exit_window();
	if (window_ptr)
	{
		while (SDL_PollEvent(&event))
		{
			printf("%d\n", value + 1);
			value += 1;
		}
	}
	renderer_ptr = SDL_CreateRenderer(window_ptr, -1,SDL_RENDERER_SOFTWARE);
	if (renderer_ptr == NULL)
		exit_renderer();
	SDL_RenderPresent(renderer_ptr);
	SDL_Delay(6000);
	if (SDL_RenderClear(renderer_ptr) != 0)
		exit(-1);
	SDL_DestroyWindow(window_ptr);
	SDL_Quit();
	return (0);
}

void		exit_window(void)
{
	SDL_Log("Error Window %s\n", SDL_GetError());
	SDL_Quit();
	exit(-1);
}

void		exit_renderer(void)
{
	SDL_Log("Error Renderer %s\n", SDL_GetError());
	SDL_Quit();
	exit(-1);
}
