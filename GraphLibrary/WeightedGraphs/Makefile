OBJS1 = main.cpp dataStruc.o
OBJS2 = testGraph.cpp graph.o dataStruc.o edge.o
OBJS3 = testGraph.cpp weightedGraph.o dataStruc.o edge.o
OBJS4 = weightedGraph.hh weightedGraph.cpp edge.hh edge.cpp dataStruc.hh dataStruc.cpp
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) --pedantic
LFLAGS = -Wall $(DEBUG) --pedantic
TARGET = grafo
TARGET2 = graph.o
TARGET3 = dataStruc.o
TARGET4 = weightedGraph.o

$(TARGET) : $(OBJS3)
	$(CC) $(LFLAGS) $(OBJS3) -o $(TARGET)

$(TARGET4) : $(OBJS4)
	$(CC) $(CFLAGS) weightedGraph.cpp

edge.o : edge.hh edge.cpp
	$(CC) $(CFLAGS) edge.cpp
	
$(TARGET2) : graph.hh graph.cpp
	$(CC) $(CFLAGS) graph.cpp
	
	
$(TARGET3) : dataStruc.hh dataStruc.cpp
	$(CC) $(CFLAGS) dataStruc.cpp

clean:
	rm -f *.o $(TARGET)
