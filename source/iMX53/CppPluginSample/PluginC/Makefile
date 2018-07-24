SRC = PluginC.cpp
INC = PluginC.h

all: $(SRC) $(INC)
	g++ -Wall -Wextra -g3 -fpic -c $(SRC)
	g++ -Wall -Wextra -nostartfiles -shared -rdynamic -o libPluginC.so PluginC.o

install:
	cp *.so ../bin/lib

uninstall:
	rm -f *.o *.so
	rm ../bin/lib/libPluginC.so

clean:
	rm -f *.o *.so
