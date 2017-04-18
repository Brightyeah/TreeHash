.PHONY = all dir

FO1 = build/main.o
FO2 = build/bstree.o
FC1 = src/main.c
FC2 = src/bstree.c
PROG = bin/main
GFLAG = gcc -Wall -o

all: clean dir $(PROG)

dir:
	mkdir build
	mkdir bin

$(FO2): $(FC2)
	$(GFLAG) $(FO2) -c $(FC2)

$(FO1): $(FC1) src/bstree.h
	$(GFLAG) $(FO1) -c $(FC1)

$(PROG): $(FO1) $(FO2)
	$(GFLAG) $(PROG) $(FO1) $(FO2)

clean:
	rm -rf build
	rm -rf bin