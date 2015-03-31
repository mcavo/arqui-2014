/***************************************************************
*setup_IDT_entry
* Inicializa un descriptor de la IDT
*
*Recibe: Puntero a elemento de la IDT
*	 Selector a cargar en el descriptor de interrupcion
*	 Puntero a rutina de atencion de interrupcion	
*	 Derechos de acceso del segmento
*	 Cero
****************************************************************/

#include "../../../include/defs.h"

void setup_IDT_entry (DESCR_INT *item, byte selector, dword offset, byte access,
			 byte cero) ;

void setup_IDT_exc(void);

void setup_IDT_pic(void);

void load_IDTR(void);
