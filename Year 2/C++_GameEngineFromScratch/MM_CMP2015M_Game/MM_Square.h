#pragma once
#ifndef aSquareFile
#define aSquareFile

#include <iostream>
#include <SDL.h>



class MM_Square
{
public:
	MM_Square();
	~MM_Square();



	void Init(int px, int py, int pw, int ph);
	void Update();
	void Input();
	void Render(SDL_Renderer* aRenderer);
	void Colour(SDL_Renderer* renderer, int R, int G, int B, int A);
	void Movement();


	//void SetColour(int eR, int eG, int eB);
	//bool MOVE_LEFT, MOVE_RIGHT;

	SDL_Window* window;
	int window_width;
	int window_height;


	SDL_Rect rec;


	int x, y, height, width, R, G, B, A;

private:


};
#endif