CC = gcc
INC_DIR = ../../src/head
TEST_DIR = ../testheaders
OBJ_DIR = ../../lib
CFLAGS= -c -Wall -I$(INC_DIR) -I$(TEST_DIR) -I$(OBJ_DIR)
LFLAGS = -Wall -I$(INC_DIR) -I$(TEST_DIR) -I$(OBJ_DIR)

all: ../bin/unit_xo

../bin/unit_xo: objects/unit_xo.c $(INC_DIR)/xen_object.h $(TEST_DIR)/test_eq.h $(OBJ_DIR)/xen_object.o; $(CC) $(LFLAGS)  objects/unit_xo.c $(OBJ_DIR)/xen_object.o -o $@ 