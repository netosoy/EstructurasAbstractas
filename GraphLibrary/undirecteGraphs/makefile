OBJS = main.cpp undirGraph.o undirGraphProc.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = main
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
undirGraph.o : undirGraph.hh undirGraph.cpp
	$(CC) $(CFLAGS) undirGraph.cpp
undirGraphProc.o : undirGraphProc.hh undirGraphProc.cpp
	$(CC) $(CFLAGS) undirGraphProc.cpp
clean:
	rm -f *.o *~ $(TARGET)