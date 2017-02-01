// Colas.h

// Directivas
#include "EstrucShed.h"

// Declaración de funciones

void InsertarProceso(EstrucSched* s, Proceso* p, short prioridad);
void ElimProceso(EstrucSched* s, long pid, short prio);
void ElimProcesoE(EstrucSched* s);
Proceso *ProxProceso(EstrucSched* s);
void CambiarEstado(EstrucSched* s, Proceso* p, char newestado);
