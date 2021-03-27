CC = gcc
CFLAGS = -Wall -Wextra -g -O2 -I../include
# truc cracra pour récupérer le chemin absolu vers le répertoire lib/
LIBDIR = $(shell dirname $(shell find $(shell pwd) | head -n 1))/lib/
LDFLAGS = -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) -ldirectory

TESTS = directory-01-test \
	directory-02 \
	directory-03 \
	directory-04 \
	directory-05 \
	directory-06 \
	directory-07 \
	hash-01.c \
	contact.c
SRC = $(TESTS:=.c)
OBJ = $(TESTS:=.o)

all: $(TESTS)

%-test: %.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean

clean:
	rm -rf *.o *~ $(TESTS)