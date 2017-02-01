// Directivas
#include "Estructuras.h"

// Devuelve la Cola deseada, dependiendo de la prioridad dada.
Cola* SeleccionarCola(EstrucSched *s, short prioridad) {

	Cola *cola; // Apuntador a la cola a usar.

	switch (prioridad) {
		case 0:
			cola = &(s->q0);
			break;
		case 1:
			cola = &(s->q1);
			break;
		case 2:
			cola = &(s->q2);
			break;
		case 3:
			cola = &(s->q3);
			break;
		case 4:
			cola = &(s->q4);
			break;
		case 5:
			cola = &(s->q5);
			break;
	}

	return cola;
}

// Inicializa los apuntadores de un proceso.
void InicializarProceso(Proceso *proceso) {
	proceso->next = NULL;
	proceso->prev = NULL;
}

// Imprime por Salida Estandar un proceso.
void ImprimeProceso(Proceso *proceso) {
	printf("\t %hi ", proceso->prioridad);
	printf("%d ", proceso->PID);
	printf("%c ", proceso->estado);
	printf("%f ", proceso->tiempo);
	printf("%c \n", *proceso->comando); // Chequear
}

// Imprime en pantalla, toda la información de la estructura de Colas.
void Imprime(EstrucSched *s) {
	int i = 0;
	Proceso *proceso;
	Cola *cola;

	for (i = 0; i < 6; i++) {
		printf("Procesos con prioridad: %d \n", i); 
		cola = SeleccionarCola(s, i);
		proceso = cola->head;
		while (proceso != NULL) {
			ImprimeProceso(proceso);
			// Siguiente proceso
			proceso = proceso->next;
		}
	}
}

// Guarda en un archivo de nombre dado, los datos de la estructura.
void Guardar(EstrucSched* s) {
	// Variables
	FILE *archivo;
	Proceso *proceso;
	int i = 0;
	Cola *cola;
	// Abre el archivo
	archivo = fopen(s->salida, "w");
	// Caso inicial
	cola = &(s->q0);
	proceso = cola->head;
	for (i = 0; i < 6; i++) {
		while (proceso != NULL) {
			// Escribe la información del proceso
			fprintf(archivo, "\t %hi ", proceso->prioridad);
			fprintf(archivo, "%d ", proceso->PID);
			fprintf(archivo, "%c ", proceso->estado);
			fprintf(archivo, "%f ", proceso->tiempo);
			fprintf(archivo, "%c \n", *proceso->comando); // Chequear

			// Cambia el proceso
			proceso = proceso->next;
		}
		// Cambia de colas
		cola = SeleccionarCola(s, i);
		proceso = cola->head;
	}
	// Cierra el archivo
	fclose(archivo);
}