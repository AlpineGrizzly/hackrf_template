CC      = cc
CFLAGS  = -Wall -g
PROG    = hackrf_temp
LDFLAGS = -lhackrf
OBJS    = main.o


%.o: %.c $(OBJS)
	$(CC) $(CFLAGS) -c -o $@ $< 

all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(PROG)


clean:
	rm -rf $(PROG) *.o
