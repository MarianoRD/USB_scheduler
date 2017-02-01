// EstrucShed.h

// Directivas
#include "Estructuras.h"


// Declaración de funciones

Cola* SeleccionarCola (EstrucSched *s, int seleccionador);
void InicializarProceso(Proceso *proceso);
void ImprimeProceso(Proceso *proceso);
void Imprime(EstrucSched *s);
void Guardar(EstrucSched* s);