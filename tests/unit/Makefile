CC = gcc
INC_DIR = ../../src/head
SRC_DIR = ../../src
TEST_DIR = ../testheaders
OBJ_DIR = ../../lib
CFLAGS=-fPIC -shared -Wall -I$(INC_DIR) -I$(SRC_DIR) -I$(TEST_DIR) -I$(OBJ_DIR)

all: binso/libunitxo.so.1

binso/libunitxo.so.1: objects/unit_xo.c  $(OBJ_DIR)/xen_object.o ; $(CC) $(CFLAGS) -o $@ $(OBJ_DIR)/xen_object.o objects/unit_xo.c