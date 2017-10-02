CC = gcc
CCPP = g++
CPPFLAGS =	-std=c++11
CPPLINK = -lstdc++
INC_DIR = include

CPP_FILES := $(wildcard src/*/*.cpp)
OBJ_FILES := $(patsubst src/%,lib/%,$(CPP_FILES:.cpp=.o))
LD_FLAGS :=
CC_FLAGS := -c $(CPPFLAGS) -Wall -I$(INC_DIR)

bin/Xenon: $(OBJ_FILES) ; $(CCPP) $(LD_FLAGS) -o $@ $^

lib/%.o: src/%.cpp
	    mkdir -p $(dir $@)
	    $(CCPP) $(CC_FLAGS) -c -o $@ $<
