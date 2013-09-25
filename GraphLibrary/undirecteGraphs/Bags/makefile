OBJS = main.cpp bag.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = main
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
stack.o : bag.hh bag.cpp
	$(CC) $(CFLAGS) bag.cpp
clean:
	rm -f *.o *~ $(TARGET)