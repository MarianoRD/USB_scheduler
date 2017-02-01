// Estructuras.h

// Directivas
#include <stdlib.h>
#include <stdio.h>

// Declaración de estructuras

typedef struct Estado
{
	char status[2];
} Estado;

typedef struct Proceso
{
	long	PID;
	Estado	estado; // L: Listo, E: EnEjecución
	short	prioridad; // Usa solo 3 bits, valores: 0-5
	float	tiempo;
	char	comando[256];
	struct 	Proceso *prev;
	struct 	Proceso *next;
	
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
	char	salida[256];
} EstrucSched;
