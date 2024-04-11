# Makefile to compile all .cpp files in src directory into executables in bin directory

# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -Wall -g

# Directories
SRCDIR = src
BINDIR = bin

# Get all .cpp files from the src directory
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
# Generate corresponding executable names in the bin directory
EXECUTABLES := $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%)

# Default target
all: $(EXECUTABLES)

# Rule to create the bin directory if it doesn't exist
$(BINDIR)/:
	mkdir -p $(BINDIR)

# Rule to compile .cpp files to executables
$(BINDIR)/%: $(SRCDIR)/%.cpp | $(BINDIR)/
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean target to remove all executables
clean:
	rm -f $(BINDIR)/*

.PHONY: all clean