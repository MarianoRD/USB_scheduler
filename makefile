# Makefile para compilar la Tarea.

# Variables
CC = gcc
CFLAGS = -g -Wall
OBJS = main.o menu.o Colas.o EstrucShed.o

# Regla all
all: pscheduler

# Creacion del ejecutable

pscheduler: $(OBJS) Estructuras.h
	gcc $(CFLAGS) -o pscheduler $(OBJS)

# Creación de los Object-Files (.o)

main.o: main.c menu.o Colas.o EstrucShed.o Estructuras.h
	gcc $(CFLAGS) -c main.c

menu.o: menu.h Colas.o EstrucShed.o Estructuras.h
	gcc $(CFLAGS) -c menu.c

Colas.o: Colas.h EstrucShed.o Estructuras.h
	gcc $(CFLAGS) -c Colas.c

EstrucShed.o: EstrucShed.h Estructuras.h
	gcc $(CFLAGS) -c EstrucShed.c

# Clean

clean: 
	rm -f pscheduler $(OBJS)