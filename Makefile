# compiler
CXX=g++

# config tools (for automatically generating compiler/linker flags)
PKGCONF=pkg-config

#linker flags
LIBS= -lsfml-graphics -lsfml-window -lsfml-system `$(PKGCONF) lua5.3 --libs`

#compiler flags
CXXFLAGS= -Wall -Werror -Iinclude/ `$(PKGCONF) lua5.3 --cflags` `$(PKGCONF) sol2 --cflags`# SFML headers should already be in /usr/include or any default include paths

src=$(wildcard src/*.cpp) \
	$(wildcard src/gui/*.cpp)

obj = $(src:.cpp=.o)

.PHONY: clashingcountries
clashingcountries: $(obj)
	$(CXX) $^ -o $@ $(LIBS)


.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.exe