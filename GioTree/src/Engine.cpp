#include "Engine.h"

std::string Engine::project_name = "default";

GLFWwindow *window;

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
	glfwSetKeyCallback(window, key_callback);

	while(!glfwWindowShouldClose(window))
	{
		Engine::Update();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	Engine::finish;
	return 0;
}

int Engine::init()
{
    	if (!glfwInit())
		return -1;
    	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    	if (!window)
    	{
       		glfwTerminate();
        	return -1;
   	}

    	glfwMakeContextCurrent(window);

	Log::info("[CORE]", "test");
	std::cout << "Project name: ";
	std::cin >> project_name;
	return 0;
}

int Engine::finish()
{
	Core::finish();
	return 0;
}
