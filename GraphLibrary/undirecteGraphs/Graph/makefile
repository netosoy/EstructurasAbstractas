OBJS = main.cpp graph.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = main
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
graph.o : graph.hh graph.cpp
	$(CC) $(CFLAGS) graph.cpp
clean:
	rm -f *.o *~ $(TARGET)