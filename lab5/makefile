# Makefile
# Victor Tadros
# CMPT 201 X01L
# Instructor: Hanan Saleh

cc = gcc
CFLAGS = -Wall -std=c99 -g

valgrind: valgrind --leak-check=yes

lab5: Player.o L5_Player_Tests.o
	$(cc) $(CFLAGS) Player.o L5_Player_Tests.o -o lab5

Player.o : Player.c
	$(cc) $(CFLAGS) Player.c -c

L5_Player_Tests.o : L5_Player_Tests.c
	$(cc) $(CFLAGS) L5_Player_Tests.c -c

.Phony:

clean: rm .o lab5

tar:
	Player.c
	Player.h
	L5_Player_Tests.c
	makefile
