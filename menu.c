// Directivas
# include <string.h>
#include "Colas.h"

// Funciones

void EjecutaAccion(EstrucSched *s, int opcion) {

	if (opcion == 1) {

		// Variables
		Proceso* nuevoProceso = InicializarProceso();

		// Se solicitan los datos
		printf("Inserte el ID del proceso (PID): ");
		scanf("%ld", &nuevoProceso->PID);
		printf("Inserte la prioridad del proceso (0-5): ");
		scanf("%hi", &nuevoProceso->prioridad);
		printf("Inserte el tiempo que tarda el proceso en ejecutarse: ");
		scanf("%f", &nuevoProceso->tiempo);
		printf("Inserte el comando del proceso: ");
		scanf("%s", nuevoProceso->comando);
		strcpy((nuevoProceso->estado).status, "L");

		// Inserta el proceso en la estructura
		InsertarProceso(s, nuevoProceso, nuevoProceso->prioridad);
	} else if (opcion == 2) {
		// Variables
		long pid = 0;
		short prioridad = 0;

		printf("Inserte el ID del proceso a eliminar (PID): ");
		scanf("%ld", &pid);
		printf("Inserte la prioridad del proceso a eliminar: ");
		scanf("%hi", &prioridad);

		// Se elimina el proceso
		ElimProceso(s, pid, prioridad);
	} else if (opcion == 3) {
		ElimProcesoE(s);
	} else if (opcion == 4) {
		Imprime(s);
	} else if (opcion ==5) {
		// Se chequea que no se este ejecutando un proceso
		if (s->ejecutando == NULL) {
			Proceso *temp;
			temp = ProxProceso(s);
			if (temp != NULL) {
				printf("Proceso seleccionado: ");
				ImprimeProceso(temp);
				printf("\n");
			}
			else {
				return;
			}
		} else {
			printf("Ya hay un proceso ejecutandose. Detenga dicho proceso");
			printf(" para poder ejecutar otro.\n");
		}
	} else if (opcion == 6) {
		// Variables
		Estado listo;
		strcpy(listo.status, "L");

		// Si no hay ningún proceso en ejecución
		if (s->ejecutando == NULL) {
			printf("No hay ningún proceso en ejecución, no se detuvo ningún proceso.\n");
			return;
		}
		// Cambia el estado
		CambiarEstado(s, s->ejecutando, listo);
		// Se le informa al usuario
		printf("Proceso: %s se ha dejado de ejecutar\n", (s->ejecutando)->comando);
		s->ejecutando = NULL;

	} else {
		printf("Opcion no válida\n");
	}

	return;
}

void ImprimeMenu(EstrucSched *s) {

	// Variables
	int opcion;

	// Imprime el menu
	printf("\n\n");
	printf("--------------- MENÚ ---------------\n\n");
	printf("1) Insertar un Proceso\n");
	printf("2) Eliminar un Proceso\n");
	printf("3) Eliminar Proceso en ejecución\n");
	printf("4) Imprimir estructura de los Procesos\n");
	printf("5) Selecciona el próximo proceso a ejecutar\n");
	printf("6) Detener proceso en ejecución\n");
	printf("0) Salir\n\n");
	// Solicita acción del usuario
	printf("Por favor introduzca el número de la opción a realizar: ");
	scanf("%d", &opcion);
	printf("\n");
	// Ejecuta
	if (opcion == 0) {
		//Se guardan los datos
		Guardar(s);
		printf("\nEstructura guardada en '%s' \n", s->salida);
		exit(0);
	} else {
		EjecutaAccion(s, opcion);
	}
	return;
}

// Construye la Estructura de Colas (6 colas con procesos).
EstrucSched *Construye(char *filename) {
	// Variables
	FILE *archivo;
	EstrucSched *estructura = malloc(sizeof(EstrucSched));
	// Abre el archivo
	printf("\nIniciando construcción del planificador.\n");
	archivo = fopen(filename, "r");

	// Empieza la lectura
	while (feof(archivo) == 0) {
		// Crea un nuevo proceso
		Proceso *proceso;
		proceso = InicializarProceso();
		// Guarda los datos del archivo en el proceso
		fscanf(archivo, "%ld %s %hi %f %s", &proceso->PID, proceso->estado.status, &proceso->prioridad, &proceso->tiempo, proceso->comando);

		// Inserta el elemento en la cola
		InsertarProceso(estructura, proceso, proceso->prioridad);
	}

	// Cierra el archivo
	fclose(archivo);
	// Comienza sin ningún proceso en ejecucion
	estructura->ejecutando = NULL;
	return estructura;
}