#include "shell.h"
#include "commands.h"
#include "lib/libc.h"
#include "../KernelSpace/system/asm/kasm.h"

void zero() {
	int a = 0;
	a = 15/a;
}
void shell(){
	char buffer[CMD_SIZE];
	char cmd[20];
	char c;
	int i;
	int j;
	while(1){
		i=0;
		printf("user@fmv-->: ");
		do {
			c=getchar();
		
			if(c=='\b'){
				if(i>0){
					i--;
					putchar(c);
				}
			}
			else{
				buffer[i]=c;
				putchar(c);
				i++;
			}
		}while(c!='\n'&& i<CMD_SIZE-1);
		if(i==CMD_SIZE-1){
			putchar('\n');
			buffer[i]=0;
		}
		else{
			buffer[i-1]=0;
		}
		j=0;
		while(buffer[j]!=' '&&j<20){
			cmd[j]=buffer[j];
			j++;
		}
		cmd[j]='\0';
		parseCommand(cmd,buffer);
		i++;
	}
}
