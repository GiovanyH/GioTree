echo "Compilando Engine..."
g++ -w -std=c++17 GioTree/src/Engine.cpp GioTree/src/log.cpp GioTree/src/core.cpp GioTree/src/window.cpp \
	GioTree/src/projectManager.cpp -lSDL2 -o GioEngine
echo "Done!"
