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

// Inicializa un proceso y los apuntadores del mismo proceso.
Proceso* InicializarProceso() {
	
	// Se crea el espacio de memoria
	Proceso* proceso = malloc(sizeof(Proceso));

	// Se inicializa la estructura
	// Se inicializan los apuntadores
	proceso->next = NULL;
	proceso->prev = NULL;

	return proceso;
}

// Imprime por Salida Estandar un proceso.
void ImprimeProceso(Proceso *proceso) {
	printf("\t %hi ", proceso->prioridad);
	printf("%ld ", proceso->PID);
	printf("%s ", (proceso->estado).status);
	printf("%f ", proceso->tiempo);
	printf("%s \n", proceso->comando); // Chequear
}

// Imprime en pantalla, toda la información de la estructura de Colas.
void Imprime(EstrucSched *s) {
	int i = 0;
	Proceso *proceso;
	Cola *cola;

	for (i = 0; i < 6; i++) {
		printf("\nProcesos con prioridad %d:\n", i); 
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

	// Se itera en las colas
	for (i = 0; i < 6; i++) {

		// Cambia de colas
		cola = SeleccionarCola(s, i);
		proceso = cola->head;

		while (proceso != NULL) {
			// Escribe la información del proceso
			fprintf(archivo, "%hi ", proceso->prioridad);
			fprintf(archivo, "%ld ", proceso->PID);
			fprintf(archivo, "%s ", proceso->estado.status);
			fprintf(archivo, "%f ", proceso->tiempo);
			fprintf(archivo, "%s \n", proceso->comando); // Chequear

			// Cambia el proceso
			proceso = proceso->next;
		}
	}
	// Cierra el archivo
	fclose(archivo);
}