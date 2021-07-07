CC=gcc
FLAG=-std=c99

all: menu

menu: menu.o abs_max.o abs_min.o sum.o diff.o
	$(CC) $(FLAG) menu.o abs_max.o abs_min.o sum.o diff.o -o menu

menu.o: menu.c abs_max.h abs_min.h sum.h diff.h
	$(CC) $(FLAG) -c menu.c

abs_max.o: abs_max.c abs_max.h
	$(CC) $(FLAG) -c abs_max.c

abs_min.o: abs_min.c abs_min.h
	$(CC) $(FLAG) -c abs_min.c

sum.o: sum.c sum.h abs_max.h
	$(CC) $(FLAG) -c sum.c

diff.o: diff.c abs_max.h abs_min.h
	$(CC) $(FLAG) -c diff.c

clean:
	rm -f *.o menu
