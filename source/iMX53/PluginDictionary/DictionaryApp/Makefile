CC=gcc
CFLAGS=-I.
LIBS=-ldl

all: DictionaryD

DictionaryD: DictionaryDaemon.o PluginManager.o
	$(CC) -o DictionaryD DictionaryDaemon.o PluginManager.o $(CFLAGS) $(LIBS)

install: DictionaryD
	cp DictionaryD ../DeployDict

clean:
	-rm *.o DictionaryD
	$(RM) ../DeployDict/DictionaryD
