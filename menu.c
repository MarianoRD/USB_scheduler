// Directivas
#include "Colas.h"

// Funciones

void EjecutaAccion(EstrucSched *s, int opcion) {

	switch(opcion) {
	case 1:
		//InsertarProceso();
		break;
	case 2:
		//ElimProceso();
		break;
	case 3:
		//ElimProcesoE();
		break;
	case 4:
		Imprime(s);
		break;		
	}
	return;
}

void ImprimeMenu(EstrucSched *s, int *salir) {

	// Variables
	int opcion;

	// Imprime el menu
	printf("1) Insertar un Proceso\n");
	printf("2) Eliminar un Proceso\n");
	printf("3) Eliminar Proceso en ejecución\n");
	printf("4) Imprimir estructura de los Procesos\n");
	printf("0) Salir\n");
	// Solicita acción del usuario
	printf("Por favor introduzca el número de la opción a realizar: \n");
	scanf("%d", &opcion);
	// Ejecuta
	if (opcion == 0) {
		*salir = 1;
	} else {
		EjecutaAccion(s, opcion);
	}
	return;
}

// Construye la Estructura de Colas (6 colas con procesos).
EstrucSched *Construye(char *filename) {
	// Variables
	FILE *archivo;
	EstrucSched estructura;
	// Abre el archivo
	archivo = fopen(filename, "r");

	// Empieza la lectura
	while (1) {
		// Crea un nuevo proceso
		Proceso proceso;
		InicializarProceso(&proceso);

		// Guarda los datos del archivo en el proceso
		fscanf(archivo, "%d %c %hi %f %s", &proceso.PID, &proceso.estado, &proceso.prioridad, &proceso.tiempo, proceso.comando);

		// Impresión de chequeo
		ImprimeProceso(&proceso);

		// Inserta el elemento en la cola
		InsertarProceso(&estructura, &proceso, proceso.prioridad);
	}
	// Cierra el archivo
	fclose(archivo);
}