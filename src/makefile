CC=g++
CFLAGS=-I$(IDIR)

IDIR =../include
ODIR =./obj
BDIR =./obj/build

_DEPS = main.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/ELFTools: $(OBJ)
	$(CC) -o $@ $^

.PHONY : clean

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*