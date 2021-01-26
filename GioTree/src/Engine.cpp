#include "Engine.h"

std::string Engine::dir = cu::current_path();
std::string Engine::project_name = "default";
std::string wDir = (Engine::dir + "/GioTree/src/kiss_sdl-master/");

window_t window;

static void dirent_read(kiss_textbox *textbox, kiss_vscrollbar *vscrollbar, kiss_label *label_sel)    
{                                                        
        Project project;     
        project.see(Engine::dir);                                    
        unsigned opt = 0;       
        if(project.projects.size() > 0)
        {
                for(int p = 0; p < project.projects.size(); ++p)
                {
			char *projectProjects = (char*)malloc(sizeof(project.projects.at(p).c_str()));
			strcpy(projectProjects, project.projects.at(p).c_str());
			kiss_array_appendstring(textbox->array, 0, projectProjects, NULL);
			free(projectProjects);
                }
        }
        if(project.projects.size() == 0 or opt == project.projects.size())
        {
                std::cout << "Criando um projeto!" << std::endl;
                std::string pName;
                std::cout << "Nome do projeto: ";
                std::cin >> pName;
                std::string pDir;
                std::cout << std::endl << "Diretorio do projeto: ";
                std::cin >> pDir;

                std::cout << std::endl;

                project.create(pName, pDir, Engine::dir);
        }
}

static void text_reset(kiss_textbox *textbox, kiss_vscrollbar *vscrollbar)    
{                                              
        qsort(textbox->array->data, textbox->array->length, sizeof(void *),    
                kiss_string_compare);                                        
        vscrollbar->step = 0.;    
        if (textbox->array->length - textbox->maxlines > 0)    
                vscrollbar->step = 1. / (textbox->array->length -    
                        textbox->maxlines);    
        textbox->firstline = 0;    
        textbox->highlightline = -1;    
        vscrollbar->fraction = 0.;    
}

/* The widget arguments are widgets that this widget talks with */
static void textbox_event(kiss_textbox *textbox, SDL_Event *e, kiss_entry *entry, int *draw)
{
        int index;

        if (kiss_textbox_event(textbox, e, draw)) {
                index = textbox->firstline + textbox->selectedline;
                if (strcmp((char *) kiss_array_data(textbox->array, index),
                        "")) {
                        kiss_string_copy(entry->text,
                                entry->textwidth / kiss_textfont.advance,
                                (char *) kiss_array_data(textbox->array,
                                index), NULL);
                        *draw = 1;
                }
        }
}

static void vscrollbar_event(kiss_vscrollbar *vscrollbar, SDL_Event *e,
        kiss_textbox *textbox2, int *draw)
{
        int firstline;

        if (kiss_vscrollbar_event(vscrollbar, e, draw) &&
                textbox2->array->length) {
                firstline = (int) ((textbox2->array->length - 
                        textbox2->maxlines) * vscrollbar->fraction + 0.5);
                if (firstline >= 0) textbox2->firstline = firstline;
                *draw = 1;
        }
}

static void projectRun(char *proDir, Project project)
{
	project.open(Engine::dir, proDir);

	std::string eDir = Engine::dir + "/GioTree/src/";
	std::string libs = eDir + "Application.cpp " + eDir + "log.cpp " + "-lSDL2";
	std::string pCPP = "g++ -w " + project.dir + "/" + project.name + ".cpp " + libs + " -o " + project.name;

	system(pCPP.c_str());

	int pid, status;

   	if (pid = fork()) { waitpid(pid, &status, 0); /* wait for the child to exit */ } 

	else { execl(project.name.c_str(), project.name.c_str(), NULL); }
}

static void button_ok1_event(kiss_button *button, SDL_Event *e,
        kiss_window *window1, kiss_entry *entry, int *draw, Project project)
{

        if (kiss_button_event(button, e, draw)) {
                window1->focus = 0;
                button->prelight = 0;
		projectRun(entry->text, project);
        }
}

static void button_cancel_event(kiss_button *button, SDL_Event *e,
        int *quit, int *draw)
{
        if (kiss_button_event(button, e, draw)) *quit = 1;
}

int Engine::init()
{
	Log::info("Engine iniciada!");
	Project project;     
        unsigned opt = 0;	
	if(project.projects.size() == 0 or opt == project.projects.size())
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
	else if(project.projects.size() > 0 && opt < project.projects.size())
	{
		project.open(dir, project.projects.at(opt));
	}

	return 0;
}

int Engine::finish()
{
	Log::info("Engine finalizada!");
	return 0;
}

int main()
{
	// Engine::init();

	Project project;
	// UI
	SDL_Renderer *renderer;
        SDL_Event e;
        kiss_array objects, a1, a2;
        kiss_window window1;
	kiss_label label = {0}, label_sel = {0};
        kiss_button button_ok1 = {0}, button_cancel = {0};
        kiss_textbox textbox = {0};
        kiss_vscrollbar vscrollbar = {0};
        kiss_progressbar progressbar = {0};
        kiss_entry entry = {0};
        int textbox_width, textbox_height, window2_width, window2_height,
                draw, quit;

        quit = 0;
        draw = 1;
        textbox_width = 320;
        textbox_height = 100;
        window2_width = 320;
        window2_height = 150;
        renderer = kiss_init(wDir.c_str(), "Escolha um projeto", &objects, 640, 300);
        if (!renderer) return 1;
        kiss_array_new(&a1);
        kiss_array_append(&objects, ARRAY_TYPE, &a1);
        kiss_array_new(&a2);
        kiss_array_append(&objects, ARRAY_TYPE, &a2);

	/* Arrange the widgets nicely relative to each other */
        kiss_window_new(&window1, NULL, 1, 0, 0, kiss_screen_width,
                kiss_screen_height);
        kiss_textbox_new(&textbox, &window1, 1, &a2,
                160, 50,
                textbox_width, textbox_height);
        kiss_vscrollbar_new(&vscrollbar, &window1, textbox.rect.x +
                textbox_width, textbox.rect.y, textbox_height);
        kiss_label_new(&label, &window1, "Projetos", textbox.rect.x +
                kiss_edge, textbox.rect.y - kiss_textfont.lineheight);
        kiss_label_new(&label_sel, &window1, "", textbox.rect.x +
                kiss_edge, textbox.rect.y + textbox_height + kiss_imagesPNG[0].h);
        kiss_entry_new(&entry, &window1, 1, "kiss", 160,
                label_sel.rect.y + kiss_textfont.lineheight,
                textbox_width);
        kiss_button_new(&button_cancel, &window1, "Cancelar",
                entry.rect.x + entry.rect.w - kiss_edge - kiss_imagesPNG[0].w,
                entry.rect.y + entry.rect.h + kiss_imagesPNG[0].h);
        kiss_button_new(&button_ok1, &window1, "Abrir", button_cancel.rect.x -
                2 * kiss_imagesPNG[0].w, button_cancel.rect.y);
	dirent_read(&textbox, &vscrollbar, &label_sel);

	/* Do that, and all widgets associated with the window will show */
        window1.visible = 1;

	// Main Engine loop
	while(!quit/* Core::running */)
	{
		SDL_Delay(10);
		if(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT) quit = 1;			

                        kiss_window_event(&window1, &e, &draw);
			textbox_event(&textbox, &e, &entry,
                                &draw);
                        vscrollbar_event(&vscrollbar, &e, &textbox,
                                &draw);
                        button_ok1_event(&button_ok1, &e, &window1, &entry, &draw, project);
                        button_cancel_event(&button_cancel, &e, &quit,
                                &draw);
                        kiss_entry_event(&entry, &e, &draw);
		}

                vscrollbar_event(&vscrollbar, NULL, &textbox, &draw);
                kiss_progressbar_event(&progressbar, NULL, &draw);

                if (!draw) continue;
                SDL_RenderClear(renderer);

		// Rendering
                kiss_window_draw(&window1, renderer);
                kiss_label_draw(&label, renderer);
                kiss_vscrollbar_draw(&vscrollbar, renderer);
                kiss_textbox_draw(&textbox, renderer);
                kiss_label_draw(&label_sel, renderer);
                kiss_entry_draw(&entry, renderer);
                kiss_button_draw(&button_ok1, renderer);
                kiss_button_draw(&button_cancel, renderer);

                SDL_RenderPresent(renderer);
                draw = 0;
	}
	kiss_clean(&objects);
	return 0;
}
