CC = gcc
CPPFLAGS =	-std=c++11
CPPLINK = -lstdc++
INC_DIR = src/head
CFLAGS = -c -Wall -I$(INC_DIR)


all: lib/xen_object.o lib/xen_bool.o lib/xen_char.o lib/xenenv.o lib/xen_int.o lib/xen_reaction.o

lib/xen_object.o: src/objects/xen_object.c $(INC_DIR)/Xenon.h; $(CC) $(CFLAGS) src/objects/xen_object.c  -o $@

lib/xen_bool.o: src/objects/xen_bool.c  $(INC_DIR)/Xenon.h; $(CC) $(CFLAGS) src/objects/xen_bool.c  -o $@

lib/xen_char.o: src/objects/xen_char.c  $(INC_DIR)/Xenon.h; $(CC) $(CFLAGS) src/objects/xen_char.c  -o $@

lib/xo_construction.o: src/parse/xo_construction.c $(INC_DIR)/Xenon.h; $(CC) $(CFLAGS) src/parse/xo_construction.c -o $@

lib/xenenv.o: src/global/xenenv.c $(INC_DIR)/Xenon.h; $(CC) $(CFLAGS) src/global/xenenv.c -o $@

lib/xen_int.o: src/objects/xen_int.c  $(INC_DIR)/Xenon.h; $(CC) $(CFLAGS) src/objects/xen_int.c  -o $@

lib/xen_reaction.o: src/reactions/xen_reaction.c  $(INC_DIR)/Xenon.h; $(CC) $(CFLAGS) src/reactions/xen_reaction.c  -o $@