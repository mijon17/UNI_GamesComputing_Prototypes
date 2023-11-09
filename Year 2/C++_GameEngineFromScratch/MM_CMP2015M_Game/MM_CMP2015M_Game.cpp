// MM_GameProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//C++ Headers
#include <iostream> // functions for printing things out
#include <string> // functions for strings

#include "SDL.h"
#include "MM_Timer.h"
#include "MM_Square.h"
#include "SDL_image.h"
#include "MM_Sprite.h"
#include "SDL_mixer.h"

//Initialising instances of class:
MM_Timer aTimer;
MM_Square aSquare;
MM_Square aSquare1;
MM_Sprite player;
MM_Sprite log1;
Mix_Music* music = NULL;
Mix_Chunk* moveSound;
MM_Sprite Win;

//SDL Event
SDL_Event _event;

//Variables:
const int FPS = 30;
bool running = false;
int counter = 0;


using namespace std;

//Main
int main(int argc, char* argv[])
{

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return 1;
	SDL_Window* window;

	SDL_INIT_TIMER;

	int window_width = 600;
	int window_height = 800;

	//Create a window
	window = SDL_CreateWindow("Mijon Mohammed CMP2015M MOH19697782 Gnatter",
		100, //Window Pos
		100, //Window Pos
		window_width, //window_width
		window_height, //window_height	
		SDL_WINDOW_RESIZABLE);

	if (window == NULL)
	{
		printf("There was an error initializing the window", SDL_GetError());
	}

	//Create a renderer which draws to the window surface
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	IMG_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_AUDIO);



	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		printf("Warning: Audio has not been found! \n");
	}
	else
	{
		moveSound = Mix_LoadWAV("Content/death.wav");
		music = Mix_LoadMUS("Content/music.mp3");
		Mix_VolumeMusic(32); //The volume for the music (0-255)
		Mix_VolumeChunk(moveSound, 128); //The Volume of this sound (0-255) 
	}
	SDL_Surface* testSprite = IMG_Load("Content/splash.png"); //created Sprite
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, testSprite);

	player.Load(renderer, "Content/Gnat.png"); //created
	log1.Load(renderer, "Content/spriteblack.png");
	Win.Load(renderer, "Content/sprite.png");


	//Initialise Classes

	aSquare.Init(300, 500, 150, 20);
	aSquare1.Init(300, 370, 150, 20);
	log1.Init(300, 200, 50, 50);
	player.Init(100, 700, 100, 100);
	Win.Init(250, 25, 100, 100);

	

	printf("Arrow Keys to move\n" "M - Mute Audio\n" "F - FullScreen\n" "Quit - Escape");
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(4000);


	//REMINDER put objects outside of while loop

	aTimer.resetTicksTimer(); // resets a frame timer to zero

	Mix_PlayMusic(music, -1);

	//start of gameloop
	while (!running)
	{

		Uint64 start = SDL_GetPerformanceCounter();

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);

		aSquare.Movement();
		aSquare.Colour(renderer, 0, 10, 0, 0);
		aSquare.Render(renderer);

		aSquare1.Update();
		aSquare1.Colour(renderer, 0, 0, 0, 100);
		aSquare1.Render(renderer);
		log1.Update();
		log1.Movement2();
		log1.Render(renderer);

		Win.Render(renderer);

		player.Input();

		if (player.CollSquare(aSquare)) {
			Mix_PlayChannel(1, moveSound, 0);
		}
		if (player.CollSquare(aSquare1)) {
			Mix_PlayChannel(1, moveSound, 0);
		}
		if (player.CollSprite(log1)) {
			Mix_PlayChannel(1, moveSound, 0);
		}

		if (player.CollSpriteWin(Win)) 
		{
			printf("Win!");
			SDL_Quit();
			IMG_Quit();
			Mix_FreeMusic(music);
			Mix_CloseAudio();
			SDL_DestroyWindow(window);
		}

		player.Update();

		player.Render(renderer);

		//Tell SDL we have finished drawing, SDL will actually show our changes:
		SDL_RenderPresent(renderer);


		//Inputs
		while (SDL_PollEvent(&_event))
		{
			if (_event.type == SDL_QUIT)
				running = true;
			if (_event.type == SDL_KEYDOWN)

			{
				switch (_event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = true;
					printf("Application Quit");
					SDL_DestroyWindow(window);
					break;

				case SDLK_f:
					printf("Window is now fullscreen! \n");
					SDL_SetWindowFullscreen(window, 1);
					break;
				case SDLK_m:
					Mix_HaltMusic();
					break;
				}
			}
		}


		printf("Timer: %i  \n", aTimer.getTicks());

		if (aTimer.getTicks() >= 60000)
		{
			running = true;
			printf("Stop\n");
		}

		Uint64 end = SDL_GetPerformanceCounter();

		float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
		SDL_Delay(floor(16.666f - elapsedMS)); //Taken from SDL Wiki Site.
		//https://thenumbat.github.io/cpp-course/sdl2/08/08.html FPS Timer

	}

	SDL_Quit();
	IMG_Quit();
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	SDL_FreeSurface(testSprite);




	//end of gameloop
}