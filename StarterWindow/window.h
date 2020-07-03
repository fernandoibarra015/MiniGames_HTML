#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Window
{
public:
	Window(const std::string& title, int width, int height);
	~Window();

	void pollEvents();
	void clear();
	void clearMap();
	SDL_Texture* loadTexture(const char* p_filePath);
	void renderer(SDL_Texture* p_tex);
	void display();
	void displayAvatar();
	void displayQuestions();
	void displayQuestions2();
	

	inline bool isClosed() { return _closed; }

private:
	bool init();

private:
	std::string _title;
	int _width = 800;
	int _height = 600;

	bool _closed = false;

	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
};
