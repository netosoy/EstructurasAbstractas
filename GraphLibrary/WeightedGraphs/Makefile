OBJS1 = edge.hh edge.cpp
OBJS2 = bag.hh bag.cpp $(OBJS1)
OBJS4 = weightedGraph.hh weightedGraph.cpp $(OBJS2)
OBJS5 = LazyPrimMST.hh LazyPrimMST.cpp $(OBJS4)
OBJS51 = EagerPrimMST.hh EagerPrimMST.cpp $(OBJS4) indexPriorityQ.o indexPriorityQ.cpp 
OBJS52 = unionFinder.hh unionFinder.cpp
OBJS53 = kruskalMST.cpp kruskalMST.hh $(OBJS52) 
OBJS6 = testGraph.cpp weightedGraph.o bag.o edge.o LazyPrimMST.o EagerPrimMST.o kruskalMST.o unionFinder.o
OBJS7 = $(OBJS5) $(OBJS6) $(OBJS51) $(OBJS53)
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) --pedantic
LFLAGS = -Wall $(DEBUG) --pedantic
TARGET = grafo


$(TARGET) : $(OBJS7)
	$(CC) $(LFLAGS) $(OBJS6) -o $(TARGET)

kruskalMST.o : $(OBJS53)
	$(CC) $(CFLAGS) kruskalMST.cpp

unionFinder.o : $(OBJS52)
	$(CC) $(CFLAGS) unionFinder.cpp

EagerPrimMST.o : $(OBJS51)
	$(CC) $(CFLAGS) EagerPrimMST.cpp
	
LazyPrimMST.o : $(OBJS5)
	$(CC) $(CFLAGS) LazyPrimMST.cpp

weightedGraph.o : $(OBJS4)
	$(CC) $(CFLAGS) weightedGraph.cpp
		
bag.o : $(OBJS2)
	$(CC) $(CFLAGS) bag.cpp

edge.o : $(OBJS1)
	$(CC) $(CFLAGS) edge.cpp
	
clean:
	rm -f *.o $(TARGET)
