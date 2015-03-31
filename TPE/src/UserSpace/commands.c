#include "commands.h"
#include "lib/libc.h"
#include "../KernelSpace/drivers/speaker.h"
#include "../KernelSpace/system/asm/kasm.h"
#include "../../include/defs.h"
#include "../KernelSpace/system/exceptions.h"

void parseCommand( char * cmd, char * buffer ) {
	if(strcmp(cmd,"echo")){
		echo(buffer);
	}
	if(strcmp(cmd,"diverrortest")){
		_zerodiv();
	}
	if(strcmp(cmd,"invalidopcodetest")){
		_invalidOpcode();
	}
	if(strcmp(cmd,"debugtest")){
		_debugtest();
	}
	if(strcmp(cmd,"idtinfo")){
		printidt();
	}
	if(strcmp(cmd,"speakertest")){
		escalerita();
	}
	if(strcmp(cmd,"biosinfo")){
		biosinfo();
	}
	if(strcmp(cmd,"help")){
		help();
	}
	if(strcmp(cmd,"who")){
		printf("Maria Victoria Cavo\t Melisa Anabella Rossi\t Franco Michel Zannini\n");
	}
	if(strcmp(cmd,"setsound")){
		setsound(buffer+9);
	}
	if(strcmp(cmd,"joysong")){
		joysong();
	}
}

void escalerita() {
	int i;
	for(i=1;i<15;i++) {
		_syscall_makesound(400+i*10,5);
	}
}

void printidt(){
	_syscall_printidt(STDOUT);
}

void biosinfo() {
	_syscall_getbiosinfo(STDOUT);
	
}

void echo( char * buffer ) {
	printf("%s\n",buffer+5);
}

void setsound(char * buffer){
	char * exception='\0';
	int excep=0, freq=0;
	int i=0, j=0;
	if(isdigit(buffer[i])){
		exception[i]=buffer[i];
		i++;
		if(isdigit(buffer[i])){
			exception[i]=buffer[i];
			i++;
		}
	}
	exception[i]='\0';
	excep=atoi(exception);
	if(buffer[i]!=' ' || excep<0 || excep>19){
		printf("Invalid exception\n");
		return;
	}
	i++;
	for(j=i; buffer[j]!='\0'; j++){
		if(!isdigit(buffer[j])){
			printf("Invalid frequency\n");
			return;
		}
	}
	freq=atoi(buffer+i);
	changeFrec(excep, freq);
}

void help(){
	printf("/*** COMMAND LIST ***/\n\n"
	" -echo <message>  (prints message)\n"
	" -idtinfo  (prints the idt table)\n"
	" -biosinfo (prints the vendor, version and date of the BIOS)\n"
	" -invalidopcodetest (launches an Invalid Opcode exception)\n"
	" -speakertest (tests the speakers with a melody)\n"
	" -diverrortest (launches a Divide Error exception)\n"
	" -debugtest (launches a Debug exception)\n"
	" -who (prints the authors)\n"
	" -setsound <exception> <frequency> (associates the frequency to the exception)\n"
	" -joysong (plays Bethoven's 'Ode To Joy' song)\n"
	"/** For more information please refer to the User Manual **/\n");
}

void joysong(){
	_syscall_makesound(247,6);
	_syscall_makesound(262,5);
	_syscall_makesound(294,4);
	_syscall_makesound(294,4);
	_syscall_makesound(262,4);
	_syscall_makesound(247,4);
	_syscall_makesound(220,4);
	_syscall_makesound(196,4);
	_syscall_makesound(196,4);
	_syscall_makesound(220,4);
	_syscall_makesound(262,4);
	_syscall_makesound(262,4);
	_syscall_makesound(220,4);
	_syscall_makesound(220,4);
}
