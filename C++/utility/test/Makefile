
CC=g++
CXXFLAGS=-std=c++0x -g -I ../include/ -I../../ThirdParty/include/
LFLAGS=-L../../ThirdParty/lib/gtest -lgtest -lpthread -L../lib/ -lnetwork
OBJ = network.o

EXE=test

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(LFLAGS)

clean:
	rm -f $(OBJ) $(EXE)
