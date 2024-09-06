
SRCS = $(wildcard *.c)
BINS = $(SRCS:.c=)
OBJS = $(SRCS:.c=.o)
MAKE = gmake

default:
	$(MAKE) all

all:	$(BINS)

%:	%.c
	cc -o $@  $^

clean:
	-rm *[0-9] *.o
