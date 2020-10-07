# this is very bad :-( and hard

CC = gcc 
CFLAGS = -Wall -Wextra -Iinclude -Llib -O0 -g

VPATH = src

all : tree.out
	
tree.out : Main.o
	$(CC) $(CFLAGS) -obin/$@ $(foreach wo,$^,bin/$(wo))

%.o : %.c
	$(CC) $(CFLAGS) -obin/$@ $< -c

clean :
	rm bin/*
