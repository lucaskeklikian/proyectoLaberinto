CC=gcc
EJECUTABLE=
HEADERS=../include

CFLAGS=-c -I$(HEADERS) -Wall
LFLAGS=
LIBS= -lm


proyecto.o: proyectoA_01.c proyectoA_02.c proyectoB_01.c 
	$(CC) $(CFLAGS)  proyectoA_01.c -o proyectoA_01.o
	$(CC) $(CFLAGS)  proyectoA_02.c -o proyectoA_02.o
	$(CC) $(CFLAGS)  proyectoB_01.c -o proyectoB_01.o
	$(CC) $(CFLAGS)  proyectoB_02.c -o proyectoB_02.o
	$(CC) $(CFLAGS)  proyectoB_03.c -o proyectoB_03.o
	$(CC) $(CFLAGS)  proyectoB_04.c -o proyectoB_04.o
	$(CC) $(CFLAGS)  proyectoB_05.c -o proyectoB_05.o
	$(CC) $(CFLAGS)  proyectoB_06.c -o proyectoB_06.o
	$(CC) $(CFLAGS)  proyectoB_07.c -o proyectoB_07.o

matriz.o: ../matriz.c
	$(CC) $(CFLAGS) ../matriz.c -omatriz.o 
	$(CC) $(CFLAGS) ../mapa.c -omapa.o
 
all: proyecto.o matriz.o
	$(CC) $(LFLAGS)proyectoA_01.o matriz.o $(LIBS) -o$ proyectoA_01.out
	$(CC) $(LFLAGS)proyectoA_02.o matriz.o $(LIBS) -o$ proyectoA_02.out
	$(CC) $(LFLAGS)proyectoB_01.o matriz.o mapa.o $(LIBS) -o$ proyectoB_01.out
	$(CC) $(LFLAGS)proyectoB_02.o matriz.o mapa.o $(LIBS) -o$ proyectoB_02.out
	$(CC) $(LFLAGS)proyectoB_02.o matriz.o mapa.o $(LIBS) -o$ proyectoB_03.out
	$(CC) $(LFLAGS)proyectoB_02.o matriz.o mapa.o $(LIBS) -o$ proyectoB_04.out
	$(CC) $(LFLAGS)proyectoB_02.o matriz.o mapa.o $(LIBS) -o$ proyectoB_05.out
	$(CC) $(LFLAGS)proyectoB_02.o matriz.o mapa.o $(LIBS) -o$ proyectoB_06.out
	$(CC) $(LFLAGS)proyectoB_02.o matriz.o mapa.o $(LIBS) -o$ proyectoB_07.out

doxy:
	doxygen ../Doxyfile
	firefox ./doxy/html/index.html

clean:
	rm -f ./*.o
	rm -f ./*.out
	rm ./doxy -rf

