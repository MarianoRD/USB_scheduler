// Directivas
  
  // Librerías de C
// Previamente incluidas en Estructuras.h

  // Librerías propias
#include "Estructuras.h"
#include "EstrucShed.h"
#include "Colas.h"


// Declaración de funciones

// Constantes y Variables Globales

// Main

int main(int argc, char* argv[]) {

  // Variables
  const void *datos = argv[1];
  const void *archsalida = argv[2];

  // Asegurarse de que hayan ingresado el nombre de ambos archivos
  if (argc < 3) {
    printf("\n");
    printf("Por favor introducir el nombre del archivo donde están los datos");
    printf(" y el nombre de archivo donde se desean guardar los datos al");
    printf(" finalizar la ejecución del programa.\n\n");
  }

  // Crea la estructura de datos EstrucShed



  return 0;
}

// Funciones