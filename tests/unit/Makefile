CC = gcc
INC_DIR = ../../src/head
TEST_DIR = ../testheaders
OBJ_DIR = ../../lib
CFLAGS= -c -Wall -I$(INC_DIR) -I$(TEST_DIR) -I$(OBJ_DIR)
LFLAGS = -Wall -I$(INC_DIR) -I$(TEST_DIR) -I$(OBJ_DIR)

all: ../bin/unit_xo ../bin/unit_xb ../bin/unit_xrx ../bin/unit_xenenv

../bin/unit_xo: objects/unit_xo.c $(INC_DIR)/Xenon.h $(TEST_DIR)/test_eq.h $(OBJ_DIR)/xen_object.o ; $(CC) $(LFLAGS) objects/unit_xo.c  $(OBJ_DIR)/xen_object.o  -o $@ 

../bin/unit_xb: objects/unit_xb.c $(INC_DIR)/Xenon.h $(TEST_DIR)/test_eq.h $(OBJ_DIR)/xen_bool.o; $(CC) $(LFLAGS) objects/unit_xb.c $(OBJ_DIR)/xen_bool.o -o $@

../bin/unit_xs: objects/unit_xs.c $(INC_DIR)/Xenon.h $(TEST_DIR)/test_eq.h $(OBJ_DIR)/xen_stream.o $(OBJ_DIR)/xen_bool.o $(OBJ_DIR)/xen_object.o; $(CC) $(LFLAGS) objects/unit_xs.c $(OBJ_DIR)/xen_stream.o $(OBJ_DIR)/xen_bool.o $(OBJ_DIR)/xen_object.o -o $@

../bin/unit_xrx: objects/unit_xrx.c $(INC_DIR)/Xenon.h $(TEST_DIR)/test_eq.h $(OBJ_DIR)/xen_reaction.o $(OBJ_DIR)/xen_object.o $(OBJ_DIR)/xen_int.o; $(CC) $(LFLAGS) objects/unit_xrx.c $(OBJ_DIR)/xen_reaction.o $(OBJ_DIR)/xen_object.o $(OBJ_DIR)/xen_int.o -o $@

../bin/unit_xenenv: objects/unit_xenenv.c $(INC_DIR)/Xenon.h $(TEST_DIR)/test_eq.h $(OBJ_DIR)/xenenv.o $(OBJ_DIR)/xengc.o $(OBJ_DIR)/xen_bool.o; $(CC) $(LFLAGS) objects/unit_xenenv.c $(INC_DIR)/Xenon.h $(TEST_DIR)/test_eq.h $(OBJ_DIR)/xenenv.o $(OBJ_DIR)/xengc.o $(OBJ_DIR)/xen_bool.o -o $@