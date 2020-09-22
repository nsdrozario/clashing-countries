CXX := g++
CXXFLAGS := -Wall -Werror -std=c++17 -fPIC -I../../include/
OBJ_DIR := ../../obj/
BIN_DIR := ../../bin/

SRCS := $(shell find -name '*.cpp' -exec basename {} \;) 
OBJS := $(addprefix $(OBJ_DIR),$(SRCS:%.cpp=%.o))

$(OBJ_DIR)%.o: %.cpp
	$(CXX) $^ -c -o $@ $(CXXFLAGS)

game_lib: $(OBJS)
	$(CXX) $(OBJS) -shared -o $(BIN_DIR)clashing_countries_game_lib$(lib_suffix) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(OBJS)
