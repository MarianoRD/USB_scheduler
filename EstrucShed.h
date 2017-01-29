// EstrucShed.h
#ifndef ESTRUCSCHED_INCLUDED
#define ESTRUCSCHED

// Directivas
#include "Estructuras.h"


// Declaración de funciones

EstrucSched *Construye(char *filename);
void Imprime(EstrucSched *s);
void Guardar(EstrucSched* s);
Cola ObtenerColaPrioridad(EstrucSched* s, short prioridad);
Cola SeleccionarCola (EstrucSched *s, int seleccionador);

#endif