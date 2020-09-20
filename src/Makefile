lib_core_util := core_util
lib_graphics := graphics
clc_libs := $(lib_core_util) $(lib_graphics)

ifeq ($(OS), Windows_NT)
	lib_suffix = .dll
else
	lib_suffix = .so
endif

export lib_suffix

all: $(clc_libs)

.PHONY: $(clc_libs)
$(clc_libs):
	$(MAKE) --directory=$@
