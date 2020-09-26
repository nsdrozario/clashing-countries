CXX := g++
PKGCONF := pkg-config
CXXFLAGS := -Wall -Werror -I../../include/ -std=c++17 `$(PKGCONF) sol2 --cflags --libs` `$(PKGCONF) lua5.3 --cflags --libs` 
OBJ_DIR := ../../obj/
BIN_DIR := ../../bin/
SRCS := $(shell find -name '*.cpp' -exec basename {} \;) 
OBJS := $(addprefix $(OBJ_DIR),$(SRCS:%.cpp=%.o))

$(OBJ_DIR)%.o: %.cpp
	$(CXX) $^ -c -o $@ $(CXXFLAGS)

core_util_lib: $(OBJS)
	$(CXX) $(OBJS) -shared -o $(BIN_DIR)libclashing_countries_core_util$(lib_suffix) $(CXXFLAGS)
