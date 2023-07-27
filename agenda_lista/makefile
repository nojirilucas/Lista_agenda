all: main

main: main.c compromisso.o agenda.o header.h
    gcc -g3 main.c compromisso.o agenda.o -o main

compromisso.o: compromisso.c header.h
    gcc -g3 -c compromisso.c

agenda.o: agenda.c header.h
    gcc -g3 agenda.c