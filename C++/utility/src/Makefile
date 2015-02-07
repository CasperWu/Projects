CC=g++
CXXFLAGS=-g
OBJ = network.o

LIB=libnetwork.a

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)
	mkdir -p ../include && cp network.h ../include/
	mkdir -p ../lib && cp $(LIB) ../lib/

clean:
	rm -f $(OBJ) $(LIB)
