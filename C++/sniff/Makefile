
CC=g++
CXXFLAGS=-std=c++0x -g -I ../utility/include/ -I/usr/local/include
LFLAGS=-L../utility/lib/ -lnetwork -L/usr/local/lib -lpcap
OBJ = sniff.o

EXE=sniff

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(LFLAGS)

clean:
	rm -f $(OBJ) $(EXE)
