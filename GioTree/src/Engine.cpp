#include "Engine.h"

std::string Engine::project_name = "default";
std::string Engine::dir = "~/" + std::string(__FILE__);

window_t window(600, 400, Engine::project_name);

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
	std::cout << "yes" << std::endl;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main()
{
	Engine::Ready();
	glfwSetKeyCallback(window.window, key_callback);

	while(!glfwWindowShouldClose(window.window))
	{
		Engine::Update();

		glfwSwapBuffers(window.window);
		glfwPollEvents();
		glfwSetWindowTitle(window.window, window.title.c_str());
	}
	Engine::finish();
	return 0;
}

int Engine::init()
{
	dir.erase(dir.end()-4, dir.end());
	dir += ".h";
	Project project;
	std::string pName;
	std::string pDir;
	std::cout << "Nome do jogo: ";
	std::cin >> pName;
	std::cout << "Diretorio do jogo: ";
	std::cin >> pDir;

	project.create(pName, pDir, dir);

	window.title = pName;

	Core::init();
	window.init();

	return 0;
}

int Engine::finish()
{
	Core::finish();
	return 0;
}
