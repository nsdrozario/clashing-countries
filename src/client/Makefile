CXX := g++
PKGCONF := pkg-config
CXXFLAGS := -Wall -Werror -std=c++17 -I../../include/ `$(PKGCONF) sol2 --cflags` `$(PKGCONF) lua5.3 --cflags`
OBJ_DIR := ../../obj/
BIN_DIR := ../../bin/
INTERNAL_LIBS = -llibclashing_countries_game -llibclashing_countries_graphics -llibclashing_countries_core_util
LDFLAGS := -L$(BIN_DIR) $(INTERNAL_LIBS) -lsfml-graphics -lsfml-window -lsfml-system `$(PKGCONF) sol2 --libs` ` $(PKGCONF) lua5.3 --libs`
SRCS := $(shell find -name '*.cpp' -exec basename {} \;) 
OBJS := $(addprefix $(OBJ_DIR),$(SRCS:%.cpp=%.o))

$(OBJ_DIR)%.o: %.cpp
	$(CXX) $^ -c -o $@ $(CXXFLAGS)

.PHONY: client
client: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(BIN_DIR)clashing_countries$(exec_suffix)