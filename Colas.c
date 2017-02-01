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
	 // Arreglar notación

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

	printf("Proceso insertado.\n");
}

void EliminarProceso(Proceso *procesoActual, Cola *cola) {
			// Chequea que no sea el primero
		if (procesoActual->prev != NULL) {
		(procesoActual->prev)->next = procesoActual->next;
		} else { // De ser el primero
			cola->head = procesoActual->next;
		}
		// Chequea que no sea el ultimo
		if (procesoActual->next != NULL) {
			(procesoActual->next)->prev = procesoActual->prev;
		}
		// Se libera la memoria
		free(procesoActual);
		printf("Proceso Eliminado.\n");
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
	int i;
	Proceso *proceso;
	Cola *cola;
	short eliminado = 0; // 0: No Eliminado
	
	// Se busca y se elimina el proceso en ejecución en todas las colas
	for (i = 0; i < 6; i++) {

		// Se cambia de cola
		cola = SeleccionarCola(s, i);
		proceso = cola->tail;

		while (proceso != NULL) {
			if (strcmp((proceso->estado).status, "L")) {
				EliminarProceso(proceso, cola);
				eliminado = 1;
				break;
			} else {
				proceso = proceso->prev;
			}
		}
		if (eliminado == 1) {
			return;
		}
	}
	// En caso de no poder eliminar un proceso.
	printf("Algo esta mal eliminando el Proceso en ejecución, pasó de 5.\n");
	printf("No hay ningún proceso en ejecución\n");
}

void CambiarEstado(EstrucSched *s, Proceso *p, Estado newestado) {
	// ¿Por qué pasan el apuntador a la estructura y al proceso?
	// ¿Se puede modificar directamente el proceso?

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
			printf("No se consiguió un proceso en la estructura\n");
			return proceso;
		}
		// Next en cabeza
		if (proceso->next == NULL) { // Si es el unico proceso de la cola
			CambiarEstado(s, proceso, ejecucion);
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

	return proceso;
}
