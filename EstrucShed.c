// Directivas
	
	// Librerías de C
#include <stdlib.h>
#include <stdio.h>
	// Librerías propias
#include "Estructuras.h"

// Declaración de funciones

// Construye la Estructura de Colas (6 colas con procesos).
EstrucSched *Construye(char *filename) {
	//
}

// Imprime en pantalla, toda la información de la estructura de Colas.
void Imprime(EstrucSched *s) {
	//
}

// Guarda en un archivo de nombre dado, los datos de la estructura.
void Guardar(EstrucSched* s) {
	//
}


// Devuelve la Cola deseada, dependiendo de la prioridad dada.
Cola ObtenerColaPrioridad(EstrucSched* s, short prioridad) {

	Cola *cola; // Apuntador a la cola a usar.

	switch (prio) {
		case 0:
		cola = &(s->q0);
		case 1:
		cola = &(s->q1);
		case 2:
		cola = &(s->q2);
		case 3:
		cola = &(s->q3);
		case 4:
		cola = &(s->q4);
		case 5:
		cola = &(s->q5);
	}

	return cola;
}

// Selecciona una cola, según un índice
Cola SeleccionarCola (EstrucSched *s, int seleccionador) {

	switch (seleccionador) {
	case 1:
		proceso = s->q1.tail;
		break;
	case 2:
		proceso = s->q2.tail;
		break;
	case 3:
		proceso = s->q3.tail;
		break;
	case 4:
		proceso = s->q4.tail;
		break;
	case 5:
		proceso = s->q5.tail;
		break;

	return seleccionador;
}

// Constantes y Variables Globales

// Variables

// Funciones

