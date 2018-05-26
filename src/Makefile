CFLAGS = -Wall -Igreatest/

.PHONY: all clean debug

SRC=$(wildcard *.c)
HEADERS=$(wildcard *.h)
EXNAME=a.out
OBJS=$(SRC:.c=.o)

%.o : %.c %.h
	gcc -c $(CFLAGS) $< -o $@

all: fix-main $(OBJS) $(HEADERS)
	gcc $(OBJS) $(CFLAGS) -o $(EXNAME)

fix-main:
	-rm main.o

clean:
	-rm *.out
	-rm *.o

debug: CFLAGS += -g
debug: all

test: CFLAGS += -DDOTEST
test: EXNAME = test.out
test: fix-main
test: all
