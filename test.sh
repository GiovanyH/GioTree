echo "Compilling..." && \
	g++ -std=c++17 Sandbox/Application.cpp GioTree/src/log.cpp GioTree/src/core.cpp GioTree/src/Engine.cpp \
	GioTree/src/window.cpp GioTree/src/projectManager.cpp -lglfw3 -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl \
	-o Sandbox/ApplicationEXE && clear && echo "Done!" && \
	./Sandbox/ApplicationEXE
