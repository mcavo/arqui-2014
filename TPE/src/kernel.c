#include "KernelSpace/system/asm/kasm.h"
#include "KernelSpace/system/idt.h"
#include "KernelSpace/drivers/video.h"
#include "UserSpace/shell.h"



/**********************************************
kmain() 
Punto de entrada de cóo C.
*************************************************/

void kmain() 
{

        //int i,num;

/* Borra la pantalla. */ 

	k_clear_screen();
	
/* CARGA LAS EXCEPCIONES */

	setup_IDT_exc();

/* CARGA DE IDT CON LA RUTINAS DE ATENCION DE LAS INT DEL PIC    */

        setup_IDT_pic();
	
/* Carga de IDTR    */

	load_IDTR();

	_Cli();
/* Habilito interrupcion de timer tick*/

        _remapPIC();
        _mascaraPIC1(0xFC);
        _mascaraPIC2(0xFF);
	
	_Sti();
	
	shell();

        while(1)
        {
	
        }
	
}

