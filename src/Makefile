CFLAGS = -Wall -Igreatest/

.PHONY: all clean debug

SRC=$(wildcard *.c)
HEADERS=$(wildcard *.h)
BUILDDIR=build
EXNAME=a.out
TMPOBJS=$(SRC:.c=.o)
OBJS=$(addprefix $(BUILDDIR)/, $(TMPOBJS))

$(BUILDDIR)/%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

all: fix-main $(OBJS) $(HEADERS)
	gcc $(OBJS) $(CFLAGS) -o $(EXNAME)

fix-main:
	-rm -f $(BUILDDIR)/main.o

clean:
	-rm -f $(BUILDDIR)/*.o
	-rm -f a.out
	-rm -f test.out

debug: CFLAGS += -g
debug: all

test: CFLAGS += -DDOTEST
test: EXNAME = test.out
test: all
