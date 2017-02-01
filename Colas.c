// Directivas
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
		p->next = NULL;
		p->prev = NULL;
		cola->head = p;
		cola->tail = p;
	} else { // Cola con al menos un elemento.
		// Actualiza apuntadores del proceso.
		p->next = NULL;
		p->prev = cola->tail;
		// Actualiza apuntadores de la cola.
		(cola->tail)->next = p;
		cola->tail = p;
	}

	printf("Proceso insertado.\n");
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
		(procesoActual->prev)->next = procesoActual->next;
		(procesoActual->next)->prev = procesoActual->prev;
		// Se libera la memoria
		free(procesoActual);
		printf("Proceso Eliminado.\n");
	} else {
		printf("El proceso ID: %li con prioridad: %hi. No se consiguió.\n", pid, prio);
	}
}

/*
* Elimina el proceso en ejecución
*/
void ElimProcesoE(EstrucSched *s) {
	/*
	* ARREGLAR SINTAXIS Y FUNCION PARA QUE PUEDA BORRAR MÁS QUE EL ÚLTIMO ELEMENTO
	*/
	// Declaraciones de variables
	int i;
	Proceso *proceso;
	Cola *cola;
	short eliminado = 0; // 0: No Eliminado

	proceso = (s->q0).tail; // Caso inicial
	
	// Se busca y se elimina el proceso en ejecución en todas las colas
	for (i = 1; i <= 5; i++) {
		while (proceso == NULL) {
			if (proceso->estado == 1) {
				(proceso->prev)->next = proceso->next;
				(proceso->next)->prev = proceso->prev;
				// Se libera la memoria
				free(proceso);
				eliminado = 1;
				break;
			} else {
				proceso = proceso->prev;
			}
		}
			if (eliminado == 1) {
				return;
			} else{ // Se cambia de cola
				cola = SeleccionarCola(s, i);
				proceso = cola->tail;
			} 
	}
	// En caso de no poder eliminar un proceso.
	printf("Algo esta mal eliminando el Proceso en ejecución, pasó de 5.\n");
	printf("No hay ningún proceso en ejecución\n");
}

Proceso *ProxProceso(EstrucSched *s) {
		// Declaraciones de variables
		Proceso *proceso = NULL;
		Cola *cola;
		int seleccionadorCola = 0;
		// Busca el primer proceso con mayor prioridad.
		while (proceso == NULL) {
			cola = SeleccionarCola(s, seleccionadorCola);
			proceso = cola->head;
			seleccionadorCola += 1;
;			if (seleccionadorCola > 5) {
				printf("Algo esta mal Seleccionando el prox Proceso en ejecución, pasó de 5.\n");
			}
	}
	return proceso;
}

void CambiarEstado(EstrucSched *s, Proceso *p, char newestado) {
	// ¿Por qué pasan el apuntador a la estructura y al proceso?
	// ¿Se puede modificar directamente el proceso?

	// Se cambia el estado del proceso
	p->estado = newestado;
}
