/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_surface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:15:37 by chbelan           #+#    #+#             */
/*   Updated: 2020/02/13 15:16:14 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "SDL.h" // include SDL header

int main(int argc, char* argv[])
{
    SDL_Surface *screen; // even with SDL2, we can still bring ancient code back
    SDL_Window *window;
    SDL_Surface *image;

    SDL_Init(SDL_INIT_VIDEO); // init video

    // create the window like normal
    window = SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    // but instead of creating a renderer, we can draw directly to the screen
    screen = SDL_GetWindowSurface(window);

    // let's just show some classic code for reference
    image = SDL_LoadBMP("box.bmp"); // loads image
    SDL_BlitSurface(image, NULL, screen, NULL); // blit it to the screen
    SDL_FreeSurface(image);

    // this works just like SDL_Flip() in SDL 1.2
    SDL_UpdateWindowSurface(window);

    // show image for 2 seconds
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
