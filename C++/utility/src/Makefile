
CC=g++
CXXFLAGS=-g
OBJ = network.o

LIB=libnetwork.a

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)
	cp network.h ../include/
	cp $(LIB) ../lib/

clean:
	rm -f $(OBJ) $(LIB)
