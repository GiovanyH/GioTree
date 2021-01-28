#CPP = clang++
#C = clang
CPP = g++
C = gcc

### 32 bit Windows

#LDFLAGS = -LC:\SDL2-2.0.8\i686-w64-mingw32\lib \
-LC:\SDL2_ttf-2.0.14\i686-w64-mingw32\lib \
-LC:\SDL2_image-2.0.3\i686-w64-mingw32\lib \
-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf \
-mwindows -m32 -march=i686
#CFLAGS = -IC:\SDL2-2.0.8\i686-w64-mingw32\include \
-IC:\SDL2-2.0.8\i686-w64-mingw32\include\SDL2 \
-IC:\SDL2_ttf-2.0.14\i686-w64-mingw32\include \
-IC:\SDL2_image-2.0.3\i686-w64-mingw32\include \
-Wall -c -std=c++17 -m32 -march=i686
#BIN = GioEngine.exe

### 64 bit Windows

#LDFLAGS = -LC:\SDL2-2.0.8\x86_64-w64-mingw32\lib \
-LC:\SDL2_ttf-2.0.14\x86_64-w64-mingw32\lib \
-LC:\SDL2_image-2.0.3\x86_64-w64-mingw32\lib \
-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf \
-mwindows
#CFLAGS = -IC:\SDL2-2.0.8\x86_64-w64-mingw32\include \
-IC:\SDL2-2.0.8\x86_64-w64-mingw32\include\SDL2 \
-IC:\SDL2_ttf-2.0.14\x86_64-w64-mingw32\include \
-IC:\SDL2_image-2.0.3\x86_64-w64-mingw32\include \
-Wall -c -std=c++17
#BIN = GioEngine.exe

### macOS

#LDFLAGS = -framework SDL2 -framework SDL2_ttf -framework SDL2_image
#CFLAGS = -I/Library/Frameworks/SDL2.framework/Headers \
-I/Library/Frameworks/SDL2_ttf.framework/Headers \
-I/Library/Frameworks/SDL2_image.framework/Headers \
-Wall -c -std=c++17
#BIN = GioEngine

### Linux

LDFLAGS = -lstdc++ -lSDL2 -lSDL2_image -lSDL2_ttf
CFLAGS = -Wall -c -std=c++17
BIN = GioEngine
all: $(BIN)

$(BIN): GioTree/src/Core/Engine.o GioTree/src/UI/kiss_sdl-master/kiss_widgets.o GioTree/src/UI/kiss_sdl-master/kiss_draw.o GioTree/src/UI/kiss_sdl-master/kiss_general.o \
GioTree/src/UI/kiss_sdl-master/kiss_posix.o GioTree/src/UI/window.o GioTree/src/projectManager/projectManager.o GioTree/src/Log/log.o GioTree/src/Editor/editor.o
	$(CPP) $^ $(LDFLAGS) -o $@

GioTree/src/Core/Engine.o: GioTree/src/Core/Engine.cpp
	$(CPP) $^ $(CFLAGS) -o $@

GioTree/src/UI/kiss_sdl-master/kiss_widgets.o: GioTree/src/UI/kiss_sdl-master/kiss_widgets.c
	$(C) $^ -o $@

GioTree/src/UI/kiss_sdl-master/kiss_draw.o: GioTree/src/UI/kiss_sdl-master/kiss_draw.c
	$(C) $^ -o $@

GioTree/src/UI/kiss_sdl-master/kiss_general.o: GioTree/src/UI/kiss_sdl-master/kiss_general.c
	$(C) $^ -o $@

GioTree/src/UI/kiss_sdl-master/kiss_posix.o: GioTree/src/UI/kiss_sdl-master/kiss_posix.c
	$(C) $^ -o $@

GioTree/src/UI/window.o: GioTree/src/UI/window.c
	$(CPP) $^ -o $@

GioTree/src/projectManager/projectManager.o: GioTree/src/projectManager/projectManager.cpp
	$(CPP) $^ $(CFLAGS) -o $@

GioTree/src/Log/log.o: GioTree/src/Log/log.cpp
	$(CPP) $^ $(CFLAGS) -o $@

GioTree/src/Editor/editor.o: GioTree/src/Editor/editor.cpp
	$(CPP) $^ $(CFLAGS) -o $@

clean:
	rm *.o && rm $(BIN)
#	del *.o
#	del $(BIN)

