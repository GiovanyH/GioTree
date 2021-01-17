#include "window.h"

window_t::window_t(unsigned wWidth, unsigned wHeight, char* wTitle)
{
	if(!glfwInit())
		Log::error("[CORE]", "Nao foi possivel inicializar GLFW", __FILE__, __LINE__);

	width = wWidth; height = wHeight;
	title = wTitle;

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if(!window)
		Log::error("[CORE]", "Nao foi possivel criar a janela", __FILE__, __LINE__);
}
