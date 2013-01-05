CFLAGS=`pkg-config --cflags glib-2.0` `pkg-config --cflags --libs gmodule-no-export-2.0` `pkg-config --cflags --libs gmodule-no-export-2.0`
LFLAGS=`pkg-config --libs glib-2.0`

EXE=test
OBJECTS=test.o

all: $(EXE)

test: $(OBJECTS)
	gcc -o test $(OBJECTS) $(LFLAGS)
#$(OBJECTS): test.c
#	gcc test.c $(CFLAGS)
clean:
	rm -f $(EXE) $(OBJECTS)
