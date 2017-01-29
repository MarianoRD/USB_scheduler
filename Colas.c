// Directivas

// Funciones

/**
*	Inserta el proceso p, en la estructura de datos.
*	Se asignan todos los apuntadores a la Cola.
*/
void InsertarProceso(EstrucSched *s, Proceso *p, short prioridad) {
	// Elije la cola correspondiente a la prioridad del proceso 'p'
	Cola *cola = ObtenerColaPrioridad(*s, prioridad);
	 // Arreglar notación

	// Agrega el elemento a la cola correspondiente
	if (cola.head == NULL) { // Cola vacía
		p->next = NULL;
		p->prev = NULL;
		cola->head = p;
		cola->tail = p;
	} else { // Cola con al menos un elemento
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
	Nodo *nodoActual = NULL;

	// Elije la cola correspondiente a la prioridad del proceso 'p'
	Cola *cola = ObtenerColaPrioridad(*s, prio);

	// Busca el nodo a eliminar
	nodoActual = &(cola->head);
	while (nodoActual->PID != pid && *(nodoActual->next) != NULL) {
		nodoActual = nodoActual->next;
	}
	if (nodoActual->PID == pid) {
		(nodoActual->prev)->next = nodoActual->next;
		(nodoActual->next)->prev = nodoActual->prev;
		// Se libera la memoria
			free(nodoActual);
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
	int i, j;
	Proceso *proceso;
	Cola *cola;
	int seleccionadorCola = 0;
	bool eliminado = false;

	proceso = s->q0.tail; // Caso inicial
	
	// Se busca y se elimina el proceso en ejecución en todas las colas
	for (i = 0; i <= 5; i++) {
		while (proceso->prev != NULL) {
			if (proceso.estado == "E") {
				(proceso->prev)->next = proceso->next;
				(proceso->next)->prev = proceso->prev;
				// Se libera la memoria
				free(proceso);
				eliminado = true;
				break;
			} else if {
				proceso = proceso->prev;
			}
		}
		if (eliminado == true) {
			break;
		} else if { // Se cambia de cola
			seleccionadorCola += 1;
			cola = SeleccionarCola(*s, seleccionadorCola);
			proceso = cola->tail;
		} else if (seleccionadorCola > 5) {
				printf("Algo esta mal eliminando el Proceso en ejecución, pasó de 5.\n");
				printf("No hay ningún proceso en ejecución\n");
		}
	}
}

Proceso *ProxProceso(EstrucSched *s) {
		// Declaraciones de variables
		Proceso *proceso;
		Cola *cola;
		int seleccionadorCola = 0;
		while (proceso == NULL) {
			cola = SeleccionarCola(*s, seleccionadorCola);
			proceso = cola->head;
			seleccionadorCola += 1;
			if (seleccionadorCola > 5) {
				printf("Algo esta mal Seleccionando el prox Proceso en ejecución, pasó de 5.\n");
			}
	}
	return proceso;
}
void CambiarEstado(EstrucSched *s, Proceso *p, newestado) {
	// ¿Por qué pasan el apuntador a la estructura y al proceso?
	// ¿Se puede modificar directamente el proceso?

	// Se cambia el estado del proceso
	p->estado = newestado;
}

// Constantes y Variables Globales

// Variables

// Funciones

