// Directivas
  
 // Librerías propias
#include "menu.h"

// Declaración de funciones

// Constantes y Variables Globales

// Main

int main(int argc, char* argv[]) {

  // Variables
  // datos = argv[1];
  // archsalida = argv[2];
  EstrucSched *estructura;

  // Asegurarse de que hayan ingresado el nombre de ambos archivos
  if (argc < 3) {
    printf("\n");
    printf("Por favor introducir el nombre del archivo donde están los datos");
    printf(" y el nombre de archivo donde se desean guardar los datos al");
    printf(" finalizar la ejecución del programa.\n\n");
    // Sale con codigo de error
    exit(-1);
  }

  // Crea la estructura de datos EstrucShed
  estructura = Construye(argv[1]);
  // Guarda el nombre del archivo de salida
  strcpy(estructura->salida, argv[2]);

  // Inicializa el ciclo y el menu
  while(1) {
    ImprimeMenu(estructura);
  }

  // Finaliza
  return 0;
}

// Funciones