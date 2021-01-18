#include "window.h"

window_t::window_t(unsigned wWidth, unsigned wHeight, std::string wTitle)
{
	if(!glfwInit())
		Log::error("[CORE]", "Nao foi possivel inicializar GLFW", __FILE__, __LINE__);

	width = wWidth; height = wHeight;
	title = wTitle;

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if(!window)
		Log::error("[CORE]", "Nao foi possivel criar a janela", __FILE__, __LINE__);
	glfwMakeContextCurrent(window);
}

window_t::~window_t()
{
	glfwTerminate();
}
