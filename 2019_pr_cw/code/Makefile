CC=gcc
FLAG=

all: vSIX clean

vSIX: cw_main.o print.o sentence.o text.o wordcount.o 1_occurrences.o 2_reverse.o 3_del.o 4_sort.o
	$(CC) $(FLAG) cw_main.o print.o sentence.o text.o wordcount.o 1_occurrences.o 2_reverse.o 3_del.o 4_sort.o -o vSIX

cw_main.o: cw_main.c print.h sentence.h text.h wordcount.h 1_occurrences.h 2_reverse.h 3_del.h 4_sort.h
	$(CC) $(FLAG) -c cw_main.c

print.o: print.c print.h
	$(CC) $(FLAG) -c print.c

sentence.o: sentence.c sentence.h
	$(CC) $(FLAG) -c sentence.c

text.o: text.c text.h
	$(CC) $(FLAG) -c text.c

wordcount.o: wordcount.c sentence.h
	$(CC) $(FLAG) -c wordcount.c

1_occurrences.o: 1_occurrences.c 1_occurrences.h
	$(CC) $(FLAG) -c 1_occurrences.c

2_reverse.o: 2_reverse.c 2_reverse.h
	$(CC) $(FLAG) -c 2_reverse.c

3_del.o: 3_del.c 3_del.h
	$(CC) $(FLAG) -c 3_del.c

4_sort.o: 4_sort.c 4_sort.h
	$(CC) $(FLAG) -c 4_sort.c

clean:
	rm -f *.o
