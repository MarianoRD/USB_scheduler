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
		Proceso *proceso;
		proceso = ProxProceso(s);
		printf("Proceso seleccionado: ");
		ImprimeProceso(proceso);
		printf("\n");
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
	printf("1) Insertar un Proceso\n");
	printf("2) Eliminar un Proceso\n");
	printf("3) Eliminar Proceso en ejecución\n");
	printf("4) Imprimir estructura de los Procesos\n");
	printf("5) Selecciona el proximo proceso\n");
	printf("0) Salir\n");
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
	archivo = fopen(filename, "r");

	// Empieza la lectura
	while (feof(archivo) == 0) {
		// Crea un nuevo proceso
		Proceso *proceso = malloc(sizeof(Proceso));
		InicializarProceso(proceso);

		// Guarda los datos del archivo en el proceso
		fscanf(archivo, "%ld %s %hi %f %s", &proceso->PID, proceso->estado.status, &proceso->prioridad, &proceso->tiempo, proceso->comando);

		// Impresión de chequeo
		ImprimeProceso(proceso);

		// Inserta el elemento en la cola
		InsertarProceso(estructura, proceso, proceso->prioridad);
	}

	// Cierra el archivo
	fclose(archivo);
	return estructura;
}