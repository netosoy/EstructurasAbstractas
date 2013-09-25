OBJS = main.cpp stack.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = main
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
stack.o : stack.hh stack.cpp
	$(CC) $(CFLAGS) stack.cpp
clean:
	rm -f *.o *~ $(TARGET)

