/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:41:26 by chbelan           #+#    #+#             */
/*   Updated: 2020/02/13 16:08:40 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int					main(int argc, char **argv)
{
	SDL_Window		*window_ptr;
	SDL_Renderer	*renderer_ptr;
	SDL_Event		event;
	SDL_Rect		rectangle;
	int				value;

	value = 0;
	rectangle.x = 250;
	rectangle.y = 250;
	rectangle.w = 450;
	rectangle.h = 450;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_exit("Failed init SDL\n");
	SDL_CreateWindowAndRenderer(1280, 720, 0, &window_ptr, &renderer_ptr);
	if (window_ptr == NULL || renderer_ptr == NULL)
		ft_exit("Error window\n");
	SDL_RenderPresent(renderer_ptr);
	if (SDL_SetRenderDrawColor(renderer_ptr, 255, 0, 0, 255) != 0)
		ft_exit("Failed set color\n");
	if (SDL_RenderDrawPoint(renderer_ptr, 100, 450) != 0)
		ft_exit("Failed draw point\n");
	if (SDL_RenderDrawLine(renderer_ptr, 200, 200, 800, 800) != 0)
		ft_exit("Failed draw line\n");
	/*if (window_ptr)
	{
		while (SDL_PollEvent(&event))
		{
			printf("%d\n", value);
			value += 1;
		}
	}*/
	SDL_Delay(7000);
	SDL_DestroyWindow(window_ptr);
	SDL_Quit();
	return (0);
}

int				ft_exit(char *str)
{
	printf("%s", str);
	SDL_Quit();
	exit(-1);
}
