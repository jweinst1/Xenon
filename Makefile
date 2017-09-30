CC = gcc
CCPP = g++
CPPFLAGS =	-std=c++11
CPPLINK = -lstdc++
INC_DIR = include

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix lib/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS :=
CC_FLAGS := -c $(CPPFLAGS) -Wall -I$(INC_DIR)

bin/Xenon: $(OBJ_FILES) ; $(CCPP) $(LD_FLAGS) -o $@ $^

lib/%.o: src/%.cpp ; $(CCPP) $(CC_FLAGS) -c -o $@ $<
