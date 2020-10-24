CC=g++
CFLAGS=-c -Wall -std=c++98
LDFLAGS=
SOURCES=TreeHashTableDemo.cpp BTNode.h BSTree.h HTable.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a3

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
