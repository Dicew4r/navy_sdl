/*
** main.c for sdl in main.c
** 
** Made by Erwan Bernard
** Login   <erwan.bernard@epitech.eu>
** 
** Started on  Thu Feb 02 22:51:57 2017 Erwan Bernard
** Last update Fri Feb 03 03:45:08 2017 Erwan Bernard
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#define LONGUEUR 1280
#define LARGEUR 720

/*
 * fct pause , attend close
 */

void pause()
{
  int continuer = 1;
  SDL_Event event;

  while (continuer)
  {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
      case SDL_QUIT:
	continuer = 0;
    }
  }
}

/*
 * set caption change le nom de la fenetre
 * loadBPM load un tupe d image sur la totaliter de la plage de la fenetre
 * Blit surface reload la fenetre
*/

int		color_window()
{
  SDL_Surface	*ecran;
  SDL_Surface	*fond;
  SDL_Surface	*textS;
  SDL_Surface	*textC;
  SDL_Surface	*textCursor;
  SDL_Rect	position;
  TTF_Font	*police;
  SDL_Color couleurNoire = {170, 170, 170};

  if ((ecran = SDL_SetVideoMode(LONGUEUR, LARGEUR, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF)) == NULL)
    return (84);
  SDL_WM_SetCaption("Navy", NULL);
  fond = SDL_LoadBMP("images/unnamed.bmp");
  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(fond, NULL, ecran, &position);
  
  police = TTF_OpenFont("oui.ttf", 70);
  textS = TTF_RenderText_Blended(police, "my pid :", couleurNoire);
  position.x = LONGUEUR / 2 - 190;
  position.y = 100;
  SDL_BlitSurface(textS, NULL, ecran, &position);

  police = TTF_OpenFont("oui.ttf", 100);
  textS = TTF_RenderText_Blended(police, "1.Serveur", couleurNoire);
  position.x = LONGUEUR / 2 - 190;
  position.y = 220;
  SDL_BlitSurface(textS, NULL, ecran, &position);

  textC = TTF_RenderText_Blended(police, "2.Client", couleurNoire);
  position.x = LONGUEUR / 2 - 150;
  position.y = 330;
  SDL_BlitSurface(textC, NULL, ecran, &position);

  SDL_Flip(ecran); // mise a jour ecran
  pause();
  SDL_FreeSurface(fond);
}

/* 
 * init sdl et load l ecran
*/

int	main(int argc, char **argv)
{

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (84);
  if(TTF_Init() == -1)
    return (84);
  color_window();
  SDL_Quit();
  TTF_Quit();
  return (0);
}
