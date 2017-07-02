CC = gcc
INC_DIR = ../../src/head
CFLAGS=-fPIC -shared -Wall -I$(INC_DIR)

libxss.so.1: xss_suite.c $(INC_DIR)/xenon_st_s.h ; $(CC) $(CFLAGS) -o $@ xss_suite.c