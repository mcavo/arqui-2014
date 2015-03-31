/***************************************************
  Bios.c
	
****************************************************/

#include "../../../include/defs.h"

byte * mem = (byte *) 0xF0000;


void getBIOS(byte *** biosData ) {
	mem = (byte *) 0xF0000;
	int i, j, lenght;
	byte checksum;
	while((dword) mem < 0x100000){
		if(mem[0]=='_' && mem[1]=='S' && mem[2]=='M' && mem[3]=='_') {
			lenght=mem[5];
			for(i=0;i<lenght;i++) {
				checksum+=mem[i];
			}
			if(checksum==0) break;
		}
		mem+=16;
		
	}
	/* mem queda en el comienzo del SMBIOS Entry Point Table */
	mem+=24; /* mem apunta al Address */
	mem=(byte *)(*((dword *)mem));
	/* string = address + lenght */
	mem+=*(mem+1);
	i=1;
	j=0;
	**biosData=(byte*)mem;
	while(i<3) {
		if(*(mem+j)==0  && i<3) {
			*((*biosData)+i)=(byte*)(mem+j+1);
			i++;
		}
		j++;
	}
}



