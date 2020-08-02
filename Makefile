.PHONY: clean

# compiler
CXX=g++

# config tools (for automatically generating compiler/linker flags)
PKGCONF=pkg-config
LUACONF=lua-config

#linker flags
LIBS= -lsfml-graphics -lsfml-window -lsfml-system `$(LUACONF) --libs`

#compiler flags
CXXFLAGS=-Wall -Werror -Iinclude/ `$(LUACONF) --include` # SFML headers should already be in /usr/include or any default include paths

obj/%.o: src/%.cpp
	$(CXX) $< -c -o $@ $(CXXFLAGS)

clashingcountries: src/clashingcountries.cpp src/extend_script.cpp
	$(CXX) *.o -o clashingcountries $(CXXFLAGS) $(LIBS)
	