CFLAGS = -Wall -Igreatest/

.PHONY: all clean debug

SRC=$(wildcard *.c)
HEADERS=$(wildcard *.h)
EXNAME=a.out
OBJS=$(SRC:.c=.o)

%.o : %.c %.h
	gcc -c $(CFLAGS) $< -o $@

all: $(OBJS) $(HEADERS)
	gcc $(OBJS) $(CFLAGS) -o $(EXNAME)

clean:
	-rm a.out
	-rm *.o
	-rm test

debug: CFLAGS += -g
debug: all

test: CFLAGS += -DDOTEST
test: EXNAME = test
test: clean
test: all