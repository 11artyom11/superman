CC=gcc
CFLAGS=
BUILDDIR=./bin
OBJDIR=$(BUILDDIR)/obj

all: prep superman

.PHONY: all clean
.SUFFIXES: .c .o


VPATH=./
OBJ=main.o

prep:
	mkdir -p $(BUILDDIR)
	mkdir -p $(OBJDIR)
superman: $(OBJ)
	$(CC) $(OBJDIR)/$(OBJ) -o $(BUILDDIR)/$@

.c.o:
	$(CC) $(CFLAGS) $< -c -o $(OBJDIR)/$@

clean:
	rm -rf $(BUILDDIR)