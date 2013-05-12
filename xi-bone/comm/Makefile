CC = gcc
CFLAGS = -Wall -mtune=cortex-a8 -march=armv7-a -O3
OBJS =
all: boneClient

boneClient: boneClient.c
	$(CC) $(CFLAGS) -o boneClient boneClient.c

clean:
	rm -rf *.o
	rm -rf boneClient
