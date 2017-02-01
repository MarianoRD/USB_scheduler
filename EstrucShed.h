// EstrucShed.h

// Directivas
#include "Estructuras.h"


// Declaración de funciones

Cola* SeleccionarCola (EstrucSched *s, int seleccionador);
Proceso* InicializarProceso();
void ImprimeProceso(Proceso *proceso);
void Imprime(EstrucSched *s);
void Guardar(EstrucSched* s);