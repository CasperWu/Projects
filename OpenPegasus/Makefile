DFLAGS = -DCIMPLE_CMPI_MODULE

objects = President.o President_Provider.o repository.o module.o# President.h President_Provider.h repository.h

all: libPresident.so

$(objects): %.o: %.cpp
	$(CC) -c $(CPPFLAGS) $(DFLAGS) $< -o $@

libPresident.so: $(objects)
	$(CC) -shared $< -o $@

clean:
	rm -f *.o
