OBJS1 = main.cpp dataStruc.o
OBJS2 = testGraph.cpp graph.o dataStruc.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) --pedantic
LFLAGS = -Wall $(DEBUG) --pedantic
TARGET = grafo
TARGET2 = graph.o
TARGET3 = dataStruc.o
$(TARGET) : $(OBJS2)
	$(CC) $(LFLAGS) $(OBJS2) -o $(TARGET)
$(TARGET2) : graph.hh graph.cpp
	$(CC) $(CFLAGS) graph.cpp
$(TARGET3) : dataStruc.hh dataStruc.cpp
	$(CC) $(CFLAGS) dataStruc.cpp
clean:
	rm -f *.o $(TARGET)
