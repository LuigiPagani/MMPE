SHELL = /bin/sh
CC = gcc
OPTIONS_AB = -O3  -Wall -c -fmessage-length=0 -MMD -MP   
OPTIONS = -O3 -Wall      
CFLAGS  =
LIBS    =
LIBS1 = -lm
GLIBS   =

MC_RRKM:
	$(CC) -c $(OPTIONS) eckart.c $(LIBS)

	$(CC)  $(OPTIONS) eckart.o   -o Eckart.exe $(LIBS1)

