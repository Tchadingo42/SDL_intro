/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:54:58 by chbelan           #+#    #+#             */
/*   Updated: 2020/02/13 15:56:13 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int			main(int argc, char **argv)
{
	SDL_Window *window = SDL_CreateWindow(
    "SDL2/OpenGL Demo", 0, 0, 640, 480, 
    SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
  
// Create an OpenGL context associated with the window.
SDL_GLContext glcontext = SDL_GL_CreateContext(window);

// now you can make GL calls.
glClearColor(0,0,0,1);
glClear(GL_COLOR_BUFFER_BIT);
SDL_GL_SwapWindow(window);

// Once finished with OpenGL functions, the SDL_GLContext can be deleted.
SDL_GL_DeleteContext(glcontext);
return(0);
}
