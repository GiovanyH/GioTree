#include "kiss_sdl-master/kiss_sdl.h"    
#include "../Log/log.h"    
     
struct window_t    
{    

        kiss_array    objects;        
	kiss_window  *window;    
        SDL_Renderer *renderer;    
     
        SDL_Event e;    
            
        unsigned width, height;    
        char *title;
             
        void init(const char *wDir) 
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
			Log::error("Nao foi possivel inicializar SDL");

		Log::info("SDL_INIT");

		Log::info("wDir is");
		Log::info(wDir);

		renderer = kiss_init(wDir, title, &objects, width, height);
		if(!renderer) Log::error("Nao foi possivel criar o renderizador");

		kiss_window_new(window, NULL, 1, 0, 0, kiss_screen_width, kiss_screen_height);
	}

	void finish()
	{
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}
};
