CC = g++
TARGET = xenon
CFLAGS = -c -Wall
OBJS = lib/main.o lib/tokenizer.o
CPPFLAGS =	-std=c++11


all: $(TARGET)

xenon: $(OBJS) ; $(CC) $(CPPFLAGS) $(OBJS) -o bin/$@


lib/main.o: src/main/main.cpp ; $(CC) $(CPPFLAGS) $(CFLAGS) src/main/main.cpp -o $@

lib/tokenizer.o: src/token/tokenizer.cpp ; $(CC) $(CPPFLAGS) $(CFLAGS) src/token/tokenizer.cpp -o $@

