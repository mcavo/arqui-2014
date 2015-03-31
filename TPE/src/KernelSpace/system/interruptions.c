/***************************************************
  Interruptions.c
	
****************************************************/

#include "../drivers/video.h"
#include "../drivers/timerTick.h"
#include "../drivers/keyboard.h"
#include "../drivers/speaker.h"
#include "../../../include/defs.h"

void int_80(int task, int file_descriptor, char* c, int count) {
	int i;
	switch(task) {
		case WRITE:
			for(i=0; i<count ; i++)
				kprint(*(c+i));	
			break;
		case READ:
			for(i=0; i<count; i++){
				*(c+i)=buffer_getchar();
	
			}
			break;
		case IDT:
			idtinfo();
			break;
		case BIOS:
			getBiosinfo();
			break;
		case SOUND:
			makesound(file_descriptor,count);//file_descriptor = frecuencia, count=cycle
			break;

	}
}

void int_08() {
	timerTick();
}

void int_09(char keycode) {
	scancode(keycode);
}


