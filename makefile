a.exe: main.o ipz.o
	gcc main.o ipz.o

main.o: main.c ipz.h
	gcc -c -Wall -g main.c

ipz.o: ipz.c ipz.h
	gcc -c -Wall -g ipz.c
