.PHONY = all dir

FOH1 = build/main_hash.o
FOH2 = build/hashtab.o
FCH1 = src/main_hash.c
FCH2 = src/hashtab.c
PROGH = bin/hash
GFLAG = gcc -Wall -o

all: clean dir $(PROGH)

dir:
	mkdir build

$(FOH1): $(FCH1) src/hashtab.h
	$(GFLAG) $(FOH1) -c $(FCH1)

$(FOH2): $(FCH2)
	$(GFLAG) $(FOH2) -c $(FCH2)

$(PROGH): $(FOH1) $(FOH2)
	$(GFLAG) $(PROGH) $(FOH1) $(FOH2)

clean:
	rm -rf build bin/*.exe
