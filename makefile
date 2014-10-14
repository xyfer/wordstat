COMPILER = gcc

all: wordstat

wordstat: wordstat.o tree.o
	$(COMPILER) wordstat.o tree.o -o wordstat

tree.o:
	$(COMPILER) -c  tree.c

wordstat.o:
	$(COMPILER) -c wordstat.c



clean:
	rm -rf *o 
	rm -rf wordstat
