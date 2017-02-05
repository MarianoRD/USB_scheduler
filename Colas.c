// Directivas
#include <string.h>
#include "EstrucShed.h"

// Funciones

/**
*	Inserta el proceso p, en la estructura de datos.
*	Se asignan todos los apuntadores a la Cola.
*/
void InsertarProceso(EstrucSched *s, Proceso *p, short prioridad) {
	// Elije la cola correspondiente a la prioridad del proceso 'p'
	Cola *cola = SeleccionarCola(s, prioridad);

	// Agrega el elemento a la cola correspondiente
	if (cola->head == NULL) { // Cola vacía
		cola->head = p;
		cola->tail = p;
	} else { // Cola con al menos un elemento.
		// Actualiza apuntadores del proceso.
		p->prev = cola->tail;
		// Actualiza apuntadores de la cola.
		(cola->tail)->next = p;
		cola->tail = p;
	}

	printf("Proceso %ld insertado.\n", p->PID);
}

void EliminarProceso(Proceso *proceso, Cola *cola) {

	if (proceso->next == NULL && proceso->prev == NULL) { // Único en la cola
		cola->head = NULL;
		cola->tail = NULL;
	} else if (proceso->prev == NULL) { //Es el primero
		cola->head = proceso->next;
		(proceso->next)->prev = NULL;
	} else if (proceso->next == NULL) { //Es el último
		cola->tail = proceso->prev;
		(proceso->prev)->next = NULL;
	} else { // Cualquier otra posición
		(proceso->prev)->next = proceso->next;
		(proceso->next)->prev = proceso->prev;
	}

	free(proceso);
	printf("\nProceso Eliminado.\n");
	return;
}

/**
*	Se busca el proceso con el PID y se elimina de la cola.
*/
void ElimProceso(EstrucSched* s, long pid, short prio) {
	// Variables
	Proceso *procesoActual = NULL;

	// Elije la cola correspondiente a la prioridad del proceso 'p'
	Cola *cola = SeleccionarCola(s, prio);

	// Busca el nodo a eliminar
	procesoActual = cola->head;
	while (procesoActual->PID != pid && procesoActual->next != NULL) {
		procesoActual = procesoActual->next;
	}

	if (procesoActual->PID == pid) {
		EliminarProceso(procesoActual, cola);
	} else {
		printf("El proceso ID: %li con prioridad: %hi. No se consiguió.\n", pid, prio);
	}
}

/*
* Elimina el proceso en ejecución
*/
void ElimProcesoE(EstrucSched *s) {

	// Declaraciones de variables
	Cola *cola;

	if (s->ejecutando == NULL) {
		printf("No hay ningún proceso en ejecución, no se eliminó ningún proceso.\n");
	} else {
		// Se busca la cola donde pertenece el proceso
		cola = SeleccionarCola(s, s->ejecutando->prioridad);

		EliminarProceso(s->ejecutando, cola);
		s->ejecutando = NULL;
	}
	return;
}

void CambiarEstado(EstrucSched *s, Proceso *p, Estado newestado) {

	// Se cambia el estado del proceso
	strcpy(p->estado.status, newestado.status);

	return;
}


Proceso *ProxProceso(EstrucSched *s) {
		// Declaraciones de variables
		Proceso *proceso = NULL;
		Cola *cola;
		int i = 0;
		Estado ejecucion;
		strcpy(ejecucion.status, "E");
		// Busca el primer proceso con mayor prioridad.
		for (i = 0; i < 6; i++) {
			cola = SeleccionarCola(s, i);
			proceso = cola->head;
			if (proceso != NULL) {
				break;
			}
		}

		// Si no hay procesos
		if (proceso == NULL) {
			printf("No se consiguieron procesos en la estructura\n");
			return proceso;
		}
		// Next en cabeza
		if (proceso->next == NULL) { // Si es el unico proceso de la cola
			CambiarEstado(s, proceso, ejecucion);
			// Se cambia el proceso en ejecucion
			s->ejecutando = proceso;
			return proceso;
		} else {
		cola->head = proceso->next;
		(proceso->next)->prev = NULL;
		}
		// Mandar proceso a tail
		proceso->next = NULL;
		InsertarProceso(s, proceso, proceso->prioridad);
		// Cambiar estado de L a E
		CambiarEstado(s, proceso, ejecucion);
		// Se cambia el proceso en ejecucion
		s->ejecutando = proceso;

	return proceso;
}
