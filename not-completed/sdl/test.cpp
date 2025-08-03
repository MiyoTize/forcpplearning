#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
using std::string;

string message = "ПОГЛАДЬ ЖУКА!!!";
int main(int argc, char* args[])
{ // 0_o
  SDL_Window* window;
  SDL_Renderer* renderer;
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Miyo was dead!\n", SDL_GetError());
  } else { // working
    window = SDL_CreateWindow("By Miyo the Crazye Tize", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    bool running = 1;
    SDL_Event event;

    while(running) {
      while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
          running = 0;
        }
      }
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);
      SDL_RenderPresent(renderer);
    }
  }
  return 0;
}
