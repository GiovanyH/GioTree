#include "Engine.h"

std::string Engine::project_name = "default";

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
	Log::info("[CORE]", "test");
	Project project;
	std::string name;
	std::string dir;
	std::cout << "Nome do jogo: ";
	std::cin >> name;
	std::cout << "Diretorio do jogo: ";
	std::cin >> dir;

	project.create(name, dir);

	window.title = name;

	Core::init();
	window.init();

	return 0;
}

int Engine::finish()
{
	Core::finish();
	return 0;
}
