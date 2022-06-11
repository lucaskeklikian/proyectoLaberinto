CC=gcc
EJECUTABLE=
HEADERS=./include

CFLAGS=-c -I$(HEADERS) -Wall
LFLAGS=
LIBS= -lm


proyecto.o: main.c  
	$(CC) $(CFLAGS) main.c -o main.o
	

laberinto.o: laberinto.c
	$(CC) $(CFLAGS) laberinto.c -olaberinto.o 
	$(CC) $(CFLAGS) mapa.c -omapa.o
 
all: main.o laberinto.o
	
	$(CC) $(LFLAGS)main.o laberinto.o mapa.o $(LIBS) -o$ main.out
	
	

doxy:
	doxygen Doxyfile
	firefox ./doxy/html/index.html

clean:
	rm -f ./*.o
	rm -f ./*.out
	rm ./doxy -rf

