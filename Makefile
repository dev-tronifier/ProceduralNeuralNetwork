PRG = NN
COMPILE_PRG = gcc -Wall -o
COMPILE_OBJ = gcc -Wall -c -o $@ $<
MAIN = test/main.c
HEADERS = include/*
CFILES = src/*
OBJ = NN

all:
	$(COMPILE_PRG) $(OBJ) $(MAIN) $(HEADERS) $(CFILES)

clean:
	rm $(OBJ)
