CC=gcc
CFLAGS=
BUILDDIR=./bin
BIN=superman
OBJDIR=$(BUILDDIR)/obj

all: prologue $(BUILDDIR)/$(BIN)

.PHONY: all
.SUFFIXES: .c .o

VPATH=./
SRC=main.c core.c logger.c
OBJ=$(patsubst %.c,$(OBJDIR)/%.o,$(SRC))
HDRS=$(patsubst %.c,$(OBJDIR)/%.h,$(SRC))

prologue:
	mkdir -p $(BUILDDIR)
	mkdir -p $(OBJDIR)

$(BUILDDIR)/$(BIN): $(OBJ)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)
