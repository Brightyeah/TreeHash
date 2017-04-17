.PHONY = all dir

FO1 = build/main.o
FO2 = build/bstree.o
FO3 = build/hashtab.o
FC1 = src/main.c
FC2 = src/bstree.c
FC3 = src/hashtab.c
PROG = bin/main
GFLAG = gcc -Wall -Werror -o

all: clean dir $(PROG)

dir:
	mkdir build
	mkdir bin

$(FO1): $(FC1)
	$(GFLAG) $(FO1) $(FC1)

$(FO2): $(FC2)
	$(GFLAG) $(FO2) $(FC2)

$(FO3): $(FC3)
	$(GFLAG) $(FO3) $(FC3)

$(PROG): $(FO1) $(FO2) $(FO3)
	$(GFLAG) $(PROG) $(FO1) $(FO2) $(FO3)

clean:
	rm -rf build
	rm -rf bin