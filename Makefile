CC = gcc
CPPFLAGS =	-std=c++11
CPPLINK = -lstdc++
INC_DIR = src/head
CFLAGS = -c -Wall -I$(INC_DIR)


all: lib/xen_object.o

lib/xen_object.o: src/objects/xen_object.c $(INC_DIR)/xen_object.h; $(CC) $(CFLAGS) src/objects/xen_object.c  -o $@