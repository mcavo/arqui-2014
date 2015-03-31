/***************************************************
  TimerTick.c
	
****************************************************/

#include "../../../include/defs.h"

dword overflow = 0;
dword count = 0;
dword flag = 0;

void timerTick() {
	if( flag !=0 ) {
		count = ( count + 1 ) % INT_MAX;
		if(count==-INT_MAX)
			overflow=1;
	}
	return;
}


void tick_wait(dword time) {
	flag=1;
	count=0;
	while(count<time && overflow==0) {
		
	}
	flag=0;
	return;
}
