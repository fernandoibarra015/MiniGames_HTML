#include "window.h"
#include "ArchivoPreguntas.h"
#include <Windows.h>
#include <iostream>

SDL_Rect destR, question, respuesta1, respuesta2, respuesta3, background;


Window::Window(const std::string& title, int width, int height) :
	_title(title), _width(width), _height(height)
{
	if (!init())
	{
		_closed = true;
	}
}

Window::~Window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}



bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Error al inicializar. \n";
		return 0;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);

	if (_window == nullptr)
	{
		std::cerr << "Error al crear ventana. \n";
		return 0;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr)
	{
		std::cerr << "Error al crear ventana. \n";
		return 0;
	}
	return true;
}

void Window::pollEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_closed = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_m:

				SDL_Texture* map = loadTexture("Map.jpeg");
				clear();
				renderer(map);
				display();
				displayAvatar();
				break;

			}

			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:

				SDL_Texture* map = loadTexture("HTML.png");
				clear();
				renderer(map);
				display();
				break;

			}

			switch (event.key.keysym.sym)
			{
			case SDLK_c:
				SDL_Texture* map = loadTexture("Image.png");
				clear();
				renderer(map);
				display();
				break;

			}

			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
				/*SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0);*/
				clear();
				display();
				displayQuestions();	
			}

			switch (event.key.keysym.sym) {
			case SDLK_1:
				SDL_Texture* incorrecto = loadTexture("incorrecto.png");
				clear();
				renderer(incorrecto);
				display();
				Sleep(2000);
				SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0);
				clear();				
				displayQuestions();
				break;
			}

			switch (event.key.keysym.sym) {
			case SDLK_2:
				SDL_Texture* correcto = loadTexture("correcto.png");
				clear();
				renderer(correcto);
				display();
				Sleep(2000);
				SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0);
				clear();
				displayQuestions2();
				break;
			}

			switch (event.key.keysym.sym) {
			case SDLK_3:
				SDL_Texture* incorrecto = loadTexture("incorrecto.png");
				clear();
				renderer(incorrecto);
				display();
				Sleep(2000);
				SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0);
				clear();
				displayQuestions();
				break;
			}
			

			switch (event.key.keysym.sym)
			{
			case SDLK_q:
				SDL_Quit();
				break;
			}

			/*switch (event.key.keysym.sym)
			{
			case SDLK_INSERT:
				regisPreguntas();
				displayQuestions();
				break;
			}*/

		default:
			break;
		}
	}
}

SDL_Texture* Window::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(_renderer, p_filePath);
	return texture;
}

void Window::clear()
{

	SDL_RenderClear(_renderer);

}

void Window::renderer(SDL_Texture* p_tex)
{
	SDL_RenderCopy(_renderer, p_tex, NULL, NULL);
}

void Window::display()
{
	SDL_RenderPresent(_renderer);
}

void Window::clearMap()
{
	SDL_SetRenderDrawColor(_renderer, 0, 255, 255, 0);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);

}

void Window::displayAvatar(){
	SDL_Texture* avatar = loadTexture("lelouch.png");
	destR.h = 64;
	destR.w = 75;
	destR.x = 270;
	destR.y = 180;
	SDL_RenderCopy(_renderer, avatar, NULL, &destR);
	SDL_RenderPresent(_renderer);
}

void Window::displayQuestions(){
	/*SDL_Texture* questions = loadTexture("question1.png");
	SDL_Texture* answer1 = loadTexture("respuesta1.png");
	SDL_Texture* answer2 = loadTexture("respuesta2.png");
	SDL_Texture* answer3 = loadTexture("respuesta3.png");*/
	SDL_Texture* backgrounds = loadTexture("Pregunta1.jpeg");

	/*question.h = 100;
	question.w = 300;
	question.x = 250;
	question.y = 50;

	respuesta1.h = 100;
	respuesta1.w = 300;
	respuesta1.x = 250;
	respuesta1.y = 230;

	respuesta2.h = 100;
	respuesta2.w = 300;
	respuesta2.x = 250;
	respuesta2.y = 325;

	respuesta3.h = 100;
	respuesta3.w = 300;
	respuesta3.x = 250;
	respuesta3.y = 410;*/

	background.w = 800;
	background.h = 600;
	background.x = 0;
	background.y = 0;

	SDL_RenderCopy(_renderer, backgrounds, NULL, &background);
	/*SDL_RenderCopy(_renderer, questions, NULL, &question);
	SDL_RenderCopy(_renderer, answer1, NULL, &respuesta1);
	SDL_RenderCopy(_renderer, answer2, NULL, &respuesta2);
	SDL_RenderCopy(_renderer, answer3, NULL, &respuesta3);*/
	

	SDL_RenderPresent(_renderer);
}

void Window::displayQuestions2() {
	SDL_Texture* questions = loadTexture("question2.png");
	SDL_Texture* answer1 = loadTexture("respuesta2-2.png");
	SDL_Texture* answer2 = loadTexture("respuesta2-1.png");
	SDL_Texture* backgrounds = loadTexture("QuestionsBackground.jpeg");

	question.h = 150;
	question.w = 325;
	question.x = 250;
	question.y = 50;

	respuesta1.h = 100;
	respuesta1.w = 300;
	respuesta1.x = 250;
	respuesta1.y = 230;

	respuesta2.h = 100;
	respuesta2.w = 300;
	respuesta2.x = 250;
	respuesta2.y = 325;

	background.w = 800;
	background.h = 600;
	background.x = 0;
	background.y = 0;

	SDL_RenderCopy(_renderer, backgrounds, NULL, &background);
	SDL_RenderCopy(_renderer, questions, NULL, &question);
	SDL_RenderCopy(_renderer, answer1, NULL, &respuesta1);
	SDL_RenderCopy(_renderer, answer2, NULL, &respuesta2);

	SDL_RenderPresent(_renderer);
}
