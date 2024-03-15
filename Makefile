CC = g++
CFLAGS = -Wall -g

# List all .cpp files in the src directory
SOURCES := $(wildcard src/*.cpp)

# Transform the source file paths to target executable names
TARGETS := $(patsubst src/%.cpp,bin/%,$(SOURCES))

all: $(TARGETS)


# Your compilation rule here
$(TARGETS): bin/% : src/%.cpp | bin
	$(CC) $(CFLAGS) -o $@ $<

# Rule to compile source files into object files
obj/%.o: src/%.cpp
	mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f bin/* obj/*

