/***************************************************
  Exceptions.c
	
****************************************************/

#include "../../../include/defs.h"
#include "../../UserSpace/lib/libc.h"
#include "../drivers/speaker.h"
#include "../drivers/speaker.h"
#include "../drivers/video.h"

uint excFrec[20] = {1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,0,2500,2600,2700,2800};

void changeFrec(int index, uint frec) {
	excFrec[index]=frec;
	return;
}

void exc (int n) {
	setScreen(RED_TXT);
	makesound(excFrec[n],5);
	switch (n) {
		
		case 0:
			printf("Exception: Divide Error\nType: Fault\n");
			break;
		case 1:
			printf("Exception: Debug\nType: Fault/Error\n");
			break;
		case 2:
			printf("Exception: NMI Interrup\nType: Interrup\n");
			break;
		case 3:
			printf("Exception: Breakpoint\nType: Trap\n");
			break;
		case 4:
			printf("Exception: Overflow\nType: Trap\n");
			break;
		case 5:
			printf("Exception: BOUND Range Exceeded\nType: Fault\n");
			break;	
		case 6:
			printf("Exception: Invalid Opcode (Undefined Opcode)\nType: Fault\n");
			break;
		case 7:
			printf("Exception: Device Not Available (No Math Coprocessor)\nType: Fault\n");
			break;
		case 8:
			makesound(excFrec[n],5);
			printf("Exception: Double fault\nType: Abort\n");
			break;	
		case 9:
			printf("Exception: Coprocessor Segment overrun\nType: Fault\n");
			break;
		case 10:
			printf("Exception: Invalid TSS\nType: Fault\n");
			break;
		case 11:
			printf("Exception: Segment Not Present\nType: Fault\n");
			break;
		case 12:
			printf("Exception: Stack-Segment Fault\nType: Fault\n");
			break;
		case 13:
			printf("Exception: General Protection\nType: Fault\n");
			break;
		case 14:
			printf("Exception: Page Fault\nType: Fault\n");
			break;	
		case 16:
			printf("Exception: x87 FPU Floating-Point Error (Math Fault)\nType: Fault\n");
			break;
		case 17:
			printf("Exception: Alignment Check\nType: Fault\n");
			break;
		case 18:
			makesound(excFrec[n],5);
			printf("Exception: Machine Check\nType: Abort\n");
			break;
		case 19:
			printf("Exception: SIMD Floating-Point Exception\nType: Fault\n");
			break;	
		default:
			printf("Unreachable");
	}
	setScreen(WHITE_TXT);
}

