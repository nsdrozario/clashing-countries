clc_libs := graphics core_util game
ifeq ($(OS), Windows_NT)
	lib_suffix = .dll
	exec_suffix = .exe
else
	lib_suffix = .so
endif

export lib_suffix
export exec_suffix

all: $(clc_libs) client

.PHONY: core_util
core_util:
	$(MAKE) --directory=core_util

.PHONY: graphics
graphics: core_util
	$(MAKE) --directory=graphics

game:
	$(MAKE) --directory=game

client: core_util graphics game
	$(MAKE) --directory=client
