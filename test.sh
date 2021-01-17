echo "Compilling..." && \
	g++ Sandbox/Application.cpp GioTree/src/log.cpp GioTree/src/core.cpp GioTree/src/Engine.cpp \
	-o Sandbox/ApplicationEXE && clear && echo "Done!" && \
	./Sandbox/ApplicationEXE
