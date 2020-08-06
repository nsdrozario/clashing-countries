.PHONY: clean

# compiler
CXX=g++

# config tools (for automatically generating compiler/linker flags)
PKGCONF=pkg-config

#linker flags
LIBS= -lsfml-graphics -lsfml-window -lsfml-system `$(PKGCONF) lua5.3 --libs`

#compiler flags
CXXFLAGS= -Wall -Werror -Iinclude/ `$(PKGCONF) lua5.3 --cflags` # SFML headers should already be in /usr/include or any default include paths

all: clean clashingcountries

obj/%.o: src/%.cpp
	$(CXX) $< -c -o $@ $(CXXFLAGS)

clashingcountries: obj/clashingcountries.o obj/extend_script.o obj/config_vars.o obj/compound_ui_element.o obj/box_label.o obj/graphics.o obj/cmdlineproc.o
	$(CXX) obj/clashingcountries.o obj/extend_script.o obj/config_vars.o obj/compound_ui_element.o obj/box_label.o obj/graphics.o obj/cmdlineproc.o -o clashingcountries $(CXXFLAGS) $(LIBS)

clean:
	rm -rf obj
	mkdir obj
	rm -rf clashingcountries

test: clashingcountries
	./clashingcountries
