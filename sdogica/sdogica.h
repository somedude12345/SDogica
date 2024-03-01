#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
  #include <SDL2/SDL.h>
 #include <SDL2/SDL_ttf.h>
 
void check();
void clearscris();
void Render();
void ClearMemory();
//void circle(int32_t centreX, int32_t centreY, int32_t diameter, int32_t parts=8);
  const char* WINDOW_TITLE = "Sdogica";
  const char* FONT_NAME = "menu_font.ttf";
  const int FONT_SIZE = 60;
  const int WINDOW_WIDTH = 1280, WINDOW_HEIGHT = 720;
 
  SDL_Window* Window; // Window created by SDL.
  SDL_Renderer* Renderer; // The renderer that shows our textures.
  SDL_Event WindowEvent; // Event capturer from SDL Window.
  SDL_Surface* TextSurface; //variabila temporara. 
SDL_Texture* title;

SDL_Texture* open;

SDL_Rect rtitle;
SDL_Rect ropen; 



