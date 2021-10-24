# Makefile for ps1b
# Flags to save on typing all this out
CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system

# Make ps1b
all:	PhotoMagic

# ps1b executable
PhotoMagic:	PhotoMagic.o FibLFSR.o
	$(CC) PhotoMagic.o FibLFSR.o -o PhotoMagic $(SFMLFLAGS)

# object files
PhotoMagic.o:	PhotoMagic.cpp FibLFSR.hpp
	$(CC) -c PhotoMagic.cpp FibLFSR.hpp $(CFLAGS)

FibLFSR.o:		FibLFSR.cpp FibLFSR.hpp
	$(CC) -c FibLFSR.cpp $(CFLAGS)

# Cleanup
clean:
	rm *.o
	rm *.gch
	rm PhotoMagic
