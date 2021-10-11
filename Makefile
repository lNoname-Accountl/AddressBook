# makefile
#
# Created by Prakasit Issanapong (Tar) 
# ID 62070503431
# Date 12/12/2019
#

EXECUTABLES=project2

all : $(EXECUTABLES)

display.o : display.c struct.h
	gcc -c display.c

read.o : read.c struct.h
	gcc -c read.c

store.o : store.c struct.h
	gcc -c store.c

search.o : search.c struct.h
	gcc -c search.c

edit.o : edit.c struct.h
	gcc -c edit.c

varidation.o : varidation.c
	gcc -c varidation.c

mainmenu.o : mainmenu.c struct.h
	gcc -c mainmenu.c

project2 : display.o read.o store.o search.o edit.o varidation.o mainmenu.o
	gcc -o project2 display.o read.o store.o search.o edit.o varidation.o mainmenu.o

clean : 
	-rm *.o
	-rm project2
