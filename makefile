a.exe: main.o ipz.o
	gcc main.o ipz.o

main.o: main.c ipz.h
	gcc -c -O3 main.c

ipz.o: ipz.c ipz.h
	gcc -c -O3 ipz.c
