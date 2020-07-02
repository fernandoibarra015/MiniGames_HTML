#include "window.h"

int main(int argc, char** argv)
{
	Window window("HTML", 800, 600);

	while (!window.isClosed())
	{
		window.pollEvents();

	}
	return 0;
}