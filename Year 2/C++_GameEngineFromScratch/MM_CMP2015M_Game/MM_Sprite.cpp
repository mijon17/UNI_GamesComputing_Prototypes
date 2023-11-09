#include "MM_Sprite.h"
#include "SDL_image.h"


SDL_Event _event1;
bool done = true;
bool isActve = true;

int currentScore = 0;


MM_Sprite::MM_Sprite()
{

}

MM_Sprite::~MM_Sprite()
{
	//SDL_DestroyTexture(texture);
	//printf("Destroyed Texture\n", texture);
}

void MM_Sprite::Init(int x, int y, int w, int h)
{
	srcRect.x = x;
	srcRect.y = y;
	srcRect.w = w;
	srcRect.h = h;




}

void MM_Sprite::Input()
{

	while (SDL_PollEvent(&_event1))
	{
		/*	if (event.type == SDL_QUIT)
				done = true;*/
		if (_event1.type == SDL_KEYDOWN /* && _event1.key.repeat == NULL */);

		{
			switch (_event1.key.keysym.sym)
			{

			case SDLK_LEFT:
				printf("Left key is Pressed!\n");
				srcRect.x -= 1;

				break;
			case SDLK_RIGHT:
				printf("Right key is pressed! \n");
				srcRect.x += 10;

				break;
			case SDLK_UP:
				printf("Up key is pressed! \n");
				srcRect.y -= 10;
				currentScore += +50;
				printf("Current Score: %i\n", currentScore);

				break;
			case SDLK_DOWN:
				printf("Down key is pressed! \n");
				srcRect.y += 10;

				break;
			}


		}
	}


}


void MM_Sprite::Update()
{



	if (srcRect.x < -50)
	{
		srcRect.x = 600;
	}
	else if (srcRect.x > 800)
	{
		srcRect.x = 0;
	}

	if (srcRect.x > 0)
	{
		//rec.x++;
	}




	if (srcRect.y < 0)
	{
		srcRect.y = 0;
	}
	else if (srcRect.y > 800)
	{
		srcRect.y = 0;
	}







}

void MM_Sprite::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, &srcRect);
}

void MM_Sprite::Load(SDL_Renderer* renderer, std::string filepath)
{
	surface = IMG_Load(filepath.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

}



bool MM_Sprite::CollSquare(MM_Square s)
{

	if (srcRect.x + srcRect.w < s.rec.x || srcRect.x > s.rec.x + s.rec.w ||
		srcRect.y + srcRect.h < s.rec.y || srcRect.y > s.rec.y + srcRect.h)
	{
		printf("New Score!: %i\n", currentScore);

		return  false;

	}

	else
	{
		printf("New Score!: %i\n", currentScore);
		printf("Collision Detected\n");
		int score1 = 1;
		currentScore -= +100;
		srcRect.y = 800;
		if (currentScore <= -1) {
			SDL_DestroyTexture(texture);
			printf("Player Has Died");
		}

	}
	return true;
}

bool MM_Sprite::CollSprite(MM_Sprite e)
{
	if (srcRect.x + srcRect.w < e.srcRect.x || srcRect.x > e.srcRect.x + e.srcRect.w ||
		srcRect.y + srcRect.h < e.srcRect.y || srcRect.y > e.srcRect.y + srcRect.h)
	{
		printf("New Score!: %i\n", currentScore);

		return  false;

	}

	else
	{
		printf("New Score!: %i\n", currentScore);
		printf("Collision Detected\n");
		int score1 = 1;
		currentScore -= 100;
		srcRect.y = 800;
		if (currentScore <= -1) {
			SDL_DestroyTexture(texture);
		}
		if (e.texture) {
		// destroy texture when collding
		}
		if (currentScore <= 2000) {
			printf("Win!");
			
		}

	}
	return true;
}

void MM_Sprite::Movement2()
{
	if ((srcRect.x + (srcRect.w)) == 800)
{
	isActve = false;

}
if (srcRect.x == -10)
{
	isActve= true;

}
if (isActve) {
	srcRect.x += 10;
}
else
{
	srcRect.x -= 10;
}
}

bool MM_Sprite::CollSpriteWin(MM_Sprite e)
{
	if (srcRect.x + srcRect.w < e.srcRect.x || srcRect.x > e.srcRect.x + e.srcRect.w ||
		srcRect.y + srcRect.h < e.srcRect.y || srcRect.y > e.srcRect.y + srcRect.h)
	{
		printf("New Score!: %i\n", currentScore);

		return  false;

	}

	else
	{
		printf("New Score!: %i\n", currentScore);
		printf("Collision Detected\n");
		int score1 = 1;
		currentScore -= 100;
	
		if (currentScore <= -1) {
			SDL_DestroyTexture(texture);
		}
		if (e.texture) {
			// destroy texture when collding
		}
		if (currentScore >= 2000) {
			printf("Win!");

		}

	}
	return true;
}



