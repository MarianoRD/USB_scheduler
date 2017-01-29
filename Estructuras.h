// Estructuras.h
#ifndef ESTRUCTURAS_INCLUDED
#define ESTRUCTURAS

// Directivas
#include <stdlib.h>
#include <stdio.h>

// Declaración de estructuras

typedef struct Proceso
{
	const 	int		PID;
	char	estado;
	short	prioridad;
	float	tiempo;
	const 	char	comando[256];
	void *prev;
	void *next;
	
} Proceso;

typedef struct Cola
{
	Proceso *head;
	Proceso *tail;
} Cola;

typedef struct EstrucSched
{
	Cola	q0;
	Cola 	q1;
	Cola 	q2;
	Cola 	q3;
	Cola 	q4;
	Cola 	q5;	
} EstrucSched;

#endif