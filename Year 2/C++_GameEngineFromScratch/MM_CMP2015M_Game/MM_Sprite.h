#pragma once
#include "SDL.h"
#include <string>
#include "MM_Square.h"


// "Simple" sprite class example outline - You need to complete the functions to make this work. This is intended to get you started, but needs a lot of
// work to make it fit for purpose. Get this working and then expand on it to make a proper sprite class for yourself.
// See the .cpp file for comments on what each function does
class MM_Sprite
{
public:
	MM_Sprite();

	~MM_Sprite();

	// you might need to rename these functions to work with your own code.. don't forget to update the CPP file too!
	void Init(int x, int y, int w, int h);
	void Input();

	void Update();
	void Render(SDL_Renderer* renderer);
	void Load(SDL_Renderer* renderer, std::string filepath);
	bool CollSquare(MM_Square s);
	bool CollSprite(MM_Sprite e);
	void Movement2();
	bool CollSpriteWin(MM_Sprite e);

	SDL_Window* window;



	// x and y position of the sprite in screen space
	int x, y = 0;

	// width and height of the sprite within the source texture
	int frameWidthPixels, frameHeightPixels = 0;

	// optional, scale the destination sprite during rendering
	int xscale, yscale = 1;
protected:
	SDL_Surface* surface;
	SDL_Texture* texture = nullptr;	// pointer to an SDL_Texture, always initialize your pointers to either NULL or nullptr
	SDL_Rect srcRect;
	inline SDL_Rect GetRect() const { return srcRect; }
	// this is the source rectangle where we will copy the sprite from within the texture
	int score = 1;

	unsigned int numberOfFrames = 1;	// how many frames of animation?
	unsigned int animationSpeed = 100;	// how many milliseconds between each frame of animation?
	unsigned int frameIndex = 0;		// which frame are we currently on?
};