CC = gcc
INC_DIR = ../../src/head
CFLAGS=-fPIC -shared -Wall -I$(INC_DIR)

all: binso/libunitxo.so.1

binso/libunitxo.so.1: objects/unit_xo.c $(INC_DIR)/xen_object.h ; $(CC) $(CFLAGS) -o $@ objects/unit_xo.c