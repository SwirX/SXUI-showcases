CC = gcc
CFLAGS = -O2 -Wall -Iinclude -Ideps/sxlist -Ideps/sxui
LDFLAGS = -Lbin -lsxui -lSDL2 -lSDL2_ttf -lm

LIST_SRC = deps/sxlist/dynamic_list.c
SXUI_SRC = deps/sxui/sxui.c

LIB_A = bin/libsxui.a

SHOWCASE_DIRS := $(wildcard showcases/*)
SHOWCASE_NAMES := $(notdir $(SHOWCASE_DIRS))

PROJECT_DIRS := $(wildcard projects/*)
PROJECT_NAMES := $(notdir $(PROJECT_DIRS))

.PHONY: all clean lib prepare folders

all: prepare folders $(LIB_A) $(SHOWCASE_NAMES) $(PROJECT_NAMES)

prepare:
	@mkdir -p include
	@cp -u deps/sxui/sxui.h include/ 2>/dev/null || :
	@cp -u deps/sxlist/dynamic_list.h include/ 2>/dev/null || :

folders:
	@mkdir -p bin

bin/dynamic_list.o: $(LIST_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

bin/sxui.o: $(SXUI_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_A): bin/sxui.o bin/dynamic_list.o
	@echo "Creating static library: $@"
	ar rcs $@ $^

lib: prepare folders $(LIB_A)

$(SHOWCASE_NAMES): %: showcases/%/main.c $(LIB_A)
	@echo "Compiling showcase: $@"
	$(CC) $(CFLAGS) $< -o bin/$@ $(LDFLAGS)

$(PROJECT_NAMES): %: projects/%/main.c $(LIB_A)
	@echo "Compiling project: $@"
	$(CC) $(CFLAGS) $< -o bin/$@ $(LDFLAGS)

clean:
	rm -rf bin/*
	rm -rf include/*.h
	@echo "Cleaned bin and include directories"
