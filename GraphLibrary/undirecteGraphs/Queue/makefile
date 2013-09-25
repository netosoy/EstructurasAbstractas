OBJS = main.cpp queue.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = main
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
stack.o : queue.hh queue.cpp
	$(CC) $(CFLAGS) queue.cpp
clean:
	rm -f *.o *~ $(TARGET)