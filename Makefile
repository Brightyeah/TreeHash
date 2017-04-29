.PHONY = all dir

FOH1 = build/main_hash.o
FOH2 = build/hashtab.o
FCH1 = src/main_hash.c
FCH2 = src/hashtab.c
PROGH = bin/hash

FOT1 = build/main_tree.o
FOT2 = build/bstree.o
FCT1 = src/main_tree.c
FCT2 = src/bstree.c
PROGT = bin/main_tree
GFLAG = gcc -Wall -o

all: clean dir $(PROGT) $(PROGH)

dir:
	mkdir build

$(FOH1): $(FCH1) src/hashtab.h
	$(GFLAG) $(FOH1) -c $(FCH1)
$(FOT1): $(FCT1) src/bstree.h
	$(GFLAG) $(FOT1) -c $(FCT1)
$(FOT2): $(FCT2)
	$(GFLAG) $(FOT2) -c $(FCT2)
$(FOH2): $(FCH2)
	$(GFLAG) $(FOH2) -c $(FCH2)

$(PROGT): $(FOT1) $(FOT2)
	$(GFLAG) $(PROGT) $(FOT1) $(FOT2)
$(PROGH): $(FOH1) $(FOH2)
	$(GFLAG) $(PROGH) $(FOH1) $(FOH2)

clean:
	rm -rf build bin/*.exe