#include "Engine.h"

std::string Engine::project_name = "default";
std::string Engine::dir = cu::current_path();

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
	Project project;

	project.see(dir);

	std::cout << "Selecione uma opçao:" << std::endl;
	for(int p = 0; p < project.projects.size()-1; ++p)
	{
		std::cout << "[" << p << "] - " << project.projects.at(p) << std::endl;
	}

	std::cout << "[" << project.projects.size()-1 << "] - Novo projeto" << std::endl;
	std::cout << ">> ";
	unsigned opt;
	std::cin >> opt;

	if(opt == project.projects.size()-1)
	{
		std::cout << "Criando um projeto!" << std::endl;
		std::string pName;
		std::cout << "Nome do projeto: ";
		std::cin >> pName;
		std::string pDir;
		std::cout << std::endl << "Diretorio do projeto: ";
		std::cin >> pDir;

		std::cout << std::endl;

		project.create(pName, pDir, dir);
	}

	window.title = "default"; // for now

	Core::init();
	window.init();

	return 0;
}

int Engine::finish()
{
	Core::finish();
	return 0;
}
