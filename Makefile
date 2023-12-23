CC=gcc
CFLAGS=
BUILDDIR=./bin
OBJDIR=$(BUILDDIR)/obj

all: prep superman

.PHONY: all clean
.SUFFIXES: .c .o


VPATH=./
OBJ=main.o core.o

prep:
	mkdir -p $(BUILDDIR)
	mkdir -p $(OBJDIR)
superman: $(OBJ)
	$(CC) $(OBJ) -o $(BUILDDIR)/$@

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(BUILDDIR)
	rm -rf *.o