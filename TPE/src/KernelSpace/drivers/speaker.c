/***************************************************
  Speaker.c
	
****************************************************/

#include "../system/asm/kasm.h"

void makesound(dword frecuency,dword cycles){
	dword f;
	f=1193180/frecuency;
	_createsound(f,cycles);
	
}
