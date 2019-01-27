CC=g++
CFLAGS=-I$(IDIR)

IDIR =../include
ODIR =./obj
BDIR =./obj/build

_DEPS = lexer.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = lexer.o main.o lexerException.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/CBF: $(OBJ)
	$(CC) -o $@ $^

.PHONY : clean

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*
