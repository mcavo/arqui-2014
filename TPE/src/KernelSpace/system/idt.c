#include "asm/kasm.h"
#include "../../../include/defs.h"

DESCR_INT idt[0x81];			
IDTR idtr;				/* IDTR */

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

void setup_IDT_entry (DESCR_INT *item, byte selector, dword offset, byte access,
			 byte cero) {
  item->selector = selector;
  item->offset_l = offset & 0xFFFF;
  item->offset_h = offset >> 16;
  item->access = access;
  item->cero = cero;
}

void load_IDTR() {
	idtr.base = 0;  
	idtr.base +=(dword) &idt;
	idtr.limit = sizeof(idt)-1;
	_lidt (&idtr);		
}

void setup_IDT_exc() {
	setup_IDT_entry (&idt[0x00], 0x08, (dword)&_exc_00_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x01], 0x08, (dword)&_exc_01_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x02], 0x08, (dword)&_exc_02_hand, ACS_INT, 0);	
	setup_IDT_entry (&idt[0x03], 0x08, (dword)&_exc_03_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x04], 0x08, (dword)&_exc_04_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x05], 0x08, (dword)&_exc_05_hand, ACS_INT, 0);	
	setup_IDT_entry (&idt[0x06], 0x08, (dword)&_exc_06_hand, ACS_INT, 0);	
	setup_IDT_entry (&idt[0x07], 0x08, (dword)&_exc_07_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x08], 0x08, (dword)&_exc_08_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x09], 0x08, (dword)&_exc_09_hand, ACS_INT, 0);	
	setup_IDT_entry (&idt[0x0A], 0x08, (dword)&_exc_0A_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x0B], 0x08, (dword)&_exc_0B_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x0C], 0x08, (dword)&_exc_0C_hand, ACS_INT, 0);	
	setup_IDT_entry (&idt[0x0D], 0x08, (dword)&_exc_0D_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x0E], 0x08, (dword)&_exc_0E_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x10], 0x08, (dword)&_exc_10_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x11], 0x08, (dword)&_exc_11_hand, ACS_INT, 0);	
	setup_IDT_entry (&idt[0x12], 0x08, (dword)&_exc_12_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x13], 0x08, (dword)&_exc_13_hand, ACS_INT, 0);
}

void setup_IDT_pic() {
	setup_IDT_entry (&idt[0x20], 0x08, (dword)&_int_08_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x21], 0x08, (dword)&_int_09_hand, ACS_INT, 0);
	setup_IDT_entry (&idt[0x80], 0x08, (dword)&_int_80_hand, ACS_INT, 0);
}
