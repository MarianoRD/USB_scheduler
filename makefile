# makefile del projecto

# Variables
CC = gcc
CFLAGS = -I
OBJECTS = main.o Estructuras.o Colas.o EstrucShed.o

# Creacion del ejecutable

pscheduler: $(OBJECTS)
	gcc -o pscheduler $(OBJECTS)

# Creación de los Object-Files (.o)

main.o: main.c Estructuras.o Colas.o EstrucShed.o
	gcc -c main.c Estructuras.o Colas.o EstrucShed.o

Estructuras.o: Estructuras.h Estructuras.c
	gcc -c Estructuras.c

Colas.o: Colas.h Colas.c Estructuras.h
	gcc -c Colas.c

EstrucShed.o: EstrucShed.h EstrucShed.c Estructuras.h
	gcc -c EstrucShed.c

# Clean

clean: rm $(OBJECTS)