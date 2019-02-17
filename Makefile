.PHONY: clean cpp js

CC = g++
EM_CC = emcc --bind
CC_FLAGS = -g -Wall


EXEC = bin/MusAI
EM_EXEC = js/MusAI.js

SOURCES = $(wildcard src/*.cpp)

OBJECTS = $(SOURCES:src/%.cpp=bin/%.o)
OBJECTS := $(filter-out bin/EmscriptenBindings.o, $(OBJECTS))

EM_OBJECTS = $(SOURCES:src/%.cpp=js/%.o)
EM_OBJECTS := $(filter-out js/Driver.o, $(EM_OBJECTS))

cpp: $(EXEC)
js: $(EM_EXEC)
valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all -v ./$(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

$(EM_EXEC): $(EM_OBJECTS)
	$(EM_CC) $(EM_OBJECTS) -o $(EM_EXEC)

bin/%.o: src/%.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

js/%.o: src/%.cpp
	$(EM_CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f bin/* js/*
