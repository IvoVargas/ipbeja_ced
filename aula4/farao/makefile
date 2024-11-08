# Makefile
# make

OBJS = farao.o\
f.o

CC=nvc++
CFLAGS=-fopenmp

all: farao

f.o: f.c
	$(CC) $(CFLAGS) f.c -c

farao.o: farao.c -c
	$(CC) $(CFLAGS) farao.c -c

farao: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o farao

clean:
	rm -f *.o
	rm -f farao