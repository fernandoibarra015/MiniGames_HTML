#include "window.h"

void correPreguntas()
{
	Window window("HTML", 800, 600);

	while (!window.isClosed())
	{
		window.pollEvents();

	}
}