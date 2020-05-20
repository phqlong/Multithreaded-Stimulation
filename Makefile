CC=gcc
CFLAGS=-I.
OBJS = pi_serial pi_multi-thread

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: pi_serial.o pi_multi-thread.o
	$(CC) -pthread -o pi_serial pi_serial.o $(CFLAGS)
	$(CC) -pthread -o pi_multi-thread pi_multi-thread.o $(CFLAGS)

clean:
	rm -f *.o $(OBJS)
