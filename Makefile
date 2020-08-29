# compiler
CXX=g++

# config tools (for automatically generating compiler/linker flags)
PKGCONF=pkg-config

#linker flags
LIBS= -lsfml-graphics -lsfml-window -lsfml-system `$(PKGCONF) lua5.3 --libs`

#compiler flags
CXXFLAGS= -Wall -Werror -Iinclude/ `$(PKGCONF) lua5.3 --cflags` `$(PKGCONF) sol2 --cflags` -std=c++17 # SFML headers should already be in /usr/include or any default include paths

OBJ= obj/clashingcountries.o obj/config_vars.o obj/extend_script.o obj/graphics.o obj/Container.o obj/Label.o obj/BaseGui.o obj/Button.o obj/RelativeCoordinates.o

obj/%.o: src/%.cpp
	$(CXX) $< -c -o $@ $(CXXFLAGS)

.PHONY: clashingcountries
clashingcountries: $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(LIBS) -o clashingcountries.exe

.PHONY: clean
clean:
	rm -rf obj
	mkdir obj
	rm -rf clashingcountries