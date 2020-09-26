clc_libs := graphics core_util game
ifeq ($(OS), Windows_NT)
	lib_suffix = .dll
else
	lib_suffix = .so
endif

export lib_suffix
export exec_suffix=.exe

all: $(clc_libs) client

.PHONY: core_util
core_util:
	$(MAKE) --directory=core_util

.PHONY: graphics
graphics: core_util
	$(MAKE) --directory=graphics

.PHONY: game
game:
	$(MAKE) --directory=game

.PHONY: client
client: core_util graphics game
	$(MAKE) --directory=client

.PHONY: clean
clean:
	rm -rf bin/
	rm -rf obj/
	mkdir bin
	mkdir obj