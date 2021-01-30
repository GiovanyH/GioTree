#include "editor.h"

static void button_ok1_event(kiss_button *button, SDL_Event *e, kiss_window *window, int *draw, std::string Engine_dir, Project project)
{
	if (kiss_button_event(button, e, draw)) {
		std::string eDir = Engine_dir + "/GioTree/src/";
		std::string libs = eDir + "Application/Application.cpp " + eDir + "Log/log.cpp " + "-lSDL2";
		std::string pCPP = "g++ -w " + project.dir + "/" + project.name + ".cpp " + libs + " -o " + project.name;

		system(pCPP.c_str());

		int pid, status;

		if (pid = fork()) { waitpid(pid, &status, 0); /* wait for the child to exit */ }
		else { execl(project.name.c_str(), project.name.c_str(), NULL); }
		std::cout << "test\n";
	}
}

void Editor::init(std::string pName, std::string pDesc, std::string pVers, std::string eDir, Project project)
{
	std::string wDir = (eDir + "/GioTree/src/UI/kiss_sdl-master/");
	projectName = pName;
	projectDescription = pDesc;
	projectVersion = pVers;

	std::cout << projectName << std::endl;
	std::cout << projectDescription << std::endl;
	std::cout << projectVersion << std::endl;

	// init
	SDL_Renderer *renderer;
	SDL_Event e;
	kiss_window window;
	kiss_array objects;
	kiss_button button_run = {0};


	renderer = kiss_init(wDir.c_str(), "Editor", &objects, 640, 300);
	if (!renderer) return;

	kiss_window_new(&window, NULL, 1, 0, 0, kiss_screen_width, kiss_screen_height);
	kiss_button_new(&button_run, &window, "Run project", 100, 100);
	window.visible = 1;

	int quit = 0;
	int draw = 0;

	while(!quit)
	{
		SDL_Delay(10);
		if(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT) quit = 1;

			kiss_window_event(&window, &e, &draw);
			button_ok1_event(&button_run, &e, &window, &draw, eDir, project);
		}

		if(!draw) continue;
		SDL_RenderClear(renderer);

		// Rendering
		kiss_window_draw(&window, renderer);
		kiss_button_draw(&button_run, renderer);

		SDL_RenderPresent(renderer);
		draw = 0;
	}
	kiss_clean(&objects);
}

void Editor::finish() {}
