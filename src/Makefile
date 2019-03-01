IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

DEPS = boolean.h listoflist.h bilangan.h managefile.h ekspresi.h fungsi.h
OBJ = bilangan.o ekspresi.o fungsi.o listoflist.o  managefile.o peubah.o LISPB.o


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

LISPB: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~
