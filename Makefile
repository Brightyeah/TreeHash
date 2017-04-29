.PHONY = all dir

FOT1 = build/main_tree.o
FOT2 = build/bstree.o
FCT1 = src/main_tree.c
FCT2 = src/bstree.c
PROGT = bin/main_tree
GFLAG = gcc -Wall -o

all: clean dir $(PROGT)

dir:
	mkdir build

$(FOT2): $(FCT2)
	$(GFLAG) $(FOT2) -c $(FCT2)

$(FOT1): $(FCT1) src/bstree.h
	$(GFLAG) $(FOT1) -c $(FCT1)

$(PROGT): $(FOT1) $(FOT2)
	$(GFLAG) $(PROGT) $(FOT1) $(FOT2)

clean:
	rm -rf build  bin/*.exe