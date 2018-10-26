# Declaration of variables
CC = g++
#CC = ~/Documents/emsdk/emscripten/1.38.12/emcc --bind
CC_FLAGS = -g -Wall
 
# File names
EXEC = bin/MusAI
#EXEC = bin/MusAI.js
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=bin/%.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
 
# To obtain object files
bin/%.o: src/%.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f bin/*