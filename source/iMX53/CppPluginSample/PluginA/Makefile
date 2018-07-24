SRC = PluginA.cpp
INC = PluginA.h

all: $(SRC) $(INC)
	g++ -Wall -Wextra -g3 -fpic -c $(SRC)
	g++ -Wall -Wextra -nostartfiles -shared -rdynamic -o libPluginA.so PluginA.o

install:
	cp *.so ../bin/lib

uninstall:
	rm -f *.o *.so
	rm ../bin/lib/libPluginA.so

clean:
	rm -f *.o *.so