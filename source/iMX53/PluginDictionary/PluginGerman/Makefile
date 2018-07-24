CFLAGS := -fPIC -g -Wall -Werror
CC := gcc
MAJOR := 0
MINOR := 1
NAME := pluginGerman
VERSION := $(MAJOR).$(MINOR)

lib: lib$(NAME).so.$(VERSION)

lib$(NAME).so.$(VERSION): $(NAME).o
	$(CC) -shared -Wl,-soname,lib$(NAME).so.$(MAJOR) $^ -o $@

install: lib
	cp libpluginGerman.so.0.1 ../DictionaryApp/plugins
	cp libpluginGerman.so.0.1 ../DeployDict/plugins

clean:
	$(RM) *.o *.so*
	$(RM) ../DictionaryApp/plugins/libpluginGerman.so.0.1
	$(RM) ../DeployDict/plugins/libpluginGerman.so.0.1
