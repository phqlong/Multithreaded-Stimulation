CC=gcc
CFLAGS=-I.
OBJS = pi_serial pi_multi-thread code

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: pi_serial.o pi_multi-thread.o code.o
	$(CC) -pthread -o pi_serial pi_serial.o $(CFLAGS)
	$(CC) -pthread -o pi_multi-thread pi_multi-thread.o $(CFLAGS)
	$(CC) -pthread -o code code.o $(CFLAGS)

clean:
	rm -f *.o $(OBJS)