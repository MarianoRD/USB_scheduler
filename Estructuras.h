// Estructuras.h

// Directivas
#include <stdlib.h>
#include <stdio.h>

// Declaración de estructuras

typedef struct Proceso
{
	int		PID;
	char	estado; // 0: Listo, 1: EnEjecución
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
