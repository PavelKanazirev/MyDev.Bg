SRC = PluginB.cpp
INC = PluginB.h

all: $(SRC) $(INC)
	g++ -Wall -Wextra -g3 -fpic -c $(SRC)
	g++ -Wall -Wextra -nostartfiles -shared -rdynamic -o libPluginB.so PluginB.o

install:
	cp *.so ../bin/lib

uninstall:
	rm -f *.o *.so
	rm ../bin/lib/libPluginB.so

clean:
	rm -f *.o *.so