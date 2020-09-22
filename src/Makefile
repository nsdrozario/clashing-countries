clc_libs := graphics core_util game
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
