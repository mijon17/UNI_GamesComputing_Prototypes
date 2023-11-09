#include "MM_Square.h" 
#include <vector>

std::vector<MM_Square*> aSquareList;
SDL_Event event;
bool quit = false;

bool right = true;


int currentscore = 0;
MM_Square::MM_Square()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square Constructed with Param(%p)", this);
}
MM_Square::~MM_Square()
{
	//SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square Destroyed with Param(%p)", this);
}

void MM_Square::Init(int px, int py, int pw, int ph)
{

	rec.x = px;
	rec.y = py;
	rec.w = pw;
	rec.h = ph;

}

void MM_Square::Update()
{


	if ((rec.x + (rec.w)) == 800)
	{
		right = false;

	}
	if (rec.x == -10)
	{
		right = true;

	}
	if (right) {
		rec.x += 5;
	}
	else
	{
		rec.x -= 5;
	}
	



}
void MM_Square::Input()
{


	while (SDL_PollEvent(&event))
	{
		/*	if (event.type == SDL_QUIT)
				done = true;*/
		if (event.type == SDL_KEYDOWN)


		{
			switch (event.key.keysym.sym)
			{

			case SDLK_LEFT:
				printf("Left key is Pressed!\n");
				rec.x -= 10;
				break;
			case SDLK_RIGHT:
				printf("Right key is pressed! \n");
				rec.x += 10;
				break;
			case SDLK_UP:
				//printf("Up key is pressed! \n");
				//rec.y -= 10;
				break;
			case SDLK_DOWN:
				//	printf("Down key is pressed! \n");
					//rec.y += 10;
				break;

			}


		}
	}

}

void MM_Square::Render(SDL_Renderer* renderer)
{

	SDL_RenderDrawRect(renderer, &rec);
	SDL_RenderFillRect(renderer, &rec);



}


void MM_Square::Colour(SDL_Renderer* renderer, int R, int G, int B, int A)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, A);
}

void MM_Square::Movement()
{
	if ((rec.x + (rec.w)) == 800)
	{
		right = false;

	}
	if (rec.x == -10)
	{
		right = true;

	}
	if (right) {
		rec.x += 8;
	}
	else
	{
		rec.x -= 8;
	}

}



