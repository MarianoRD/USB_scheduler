// Colas.h

// Directivas
#include "EstrucShed.h"
#include <string.h>

// Declaración de funciones

void InsertarProceso(EstrucSched* s, Proceso* p, short prioridad);
void EliminarProceso(Proceso *procesoActual, Cola *cola);
void ElimProceso(EstrucSched* s, long pid, short prio);
void ElimProcesoE(EstrucSched* s);
void CambiarEstado(EstrucSched* s, Proceso* p, Estado newestado);
Proceso *ProxProceso(EstrucSched* s);
