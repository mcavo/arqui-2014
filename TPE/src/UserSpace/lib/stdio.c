/***************************************************
  Stdio.c
	
****************************************************/
#include "../../KernelSpace/system/asm/kasm.h"
#include "stdarg.h"
#include "libc.h"
#include "../../../include/defs.h"

void getd(int * d){
	char c;
	int res=0;
	int isnum=1;
	while(isnum){
		c=getchar();
		putchar(c);
		if(isdigit(c)){
			res=res*10;	
			res+=(c-'0');
		}
		else{
			isnum=0;
		}
	}
	*d=res;
	return ;
}

void printf (const char *string,...) {
	int i = 0;
	int j;
	char char_value;
	char* string_value;
	char next_char;

	va_list args;
	va_start(args,string);

	while (string[i] != '\0') {
		if (string[i] != '%' && string[i] != '\\') {
			putchar(string[i]); 
		} else {
			switch (string[i]) {
			case '%': {
				next_char = string[i + 1];
				switch (next_char) {
				case 'd': 
					itoa(va_arg(args,int),string_value);
					for (j = 0; string_value[j] != '\0'; j++) {
						putchar(string_value[j]);
					}
					i++;
					break;
				case 'x':
					xtoa(va_arg(args,int),string_value);
					for (j = 0; string_value[j] != '\0'; j++) {
						putchar(string_value[j]);
					}
					i++;
					break;
				case 's': 
					string_value=va_arg(args,char*);
					for (j = 0; string_value[j] != '\0'; j++) {
						putchar(string_value[j]);
					}
					i++;
					break;
				case 'c':
					char_value = va_arg(args,char);
					putchar(char_value);					
					i++;
				default:
					putchar(string[i]);
					break;
				}
			}
				break;
			case '\\':
				next_char = string[i + 1];
				if (next_char == 'n') {
					putchar('\n'); 
				} else {
					putchar('\\'); 
				}
				break;
			}

		}
		i++;

	}
	va_end(args);


}

void scanf (const char * string, ...) {
	char* string_value;
	char next_char;
	char * c;
	int i;
	int j;
	va_list args;
	va_start(args,string);

	while (string[i] != '\0') {
		if (string[i] != '%') {
		} else {
			switch (string[i]) {
			case '%': {
				next_char = string[i + 1];
				switch (next_char) {
				case 'd':
					getd(va_arg(args,int *));
					i++;
					break;
				case 's':
					string_value=va_arg(args,char*);
					next_char=getchar();
					for (j = 0; next_char!= ' '; j++) {
						string_value[j]=next_char;
						putchar(next_char);
						next_char=getchar();
					}
					string_value[j]='\0';
					i++;
					break;
				case 'c':
					c=va_arg(args,char*);
					*c=getchar();
					putchar(*c);					
					i++;
					break;
				}

			}
			}
		}
		i++;

	}
	va_end(args);
	return ;
}

int putchar (char c) {
	_syscall_write(STDOUT,&c,1);
	return 0;
}

char getchar () {
	char c=0;
	do{
	_syscall_read(STDIN,&c,1);
	}while(c==0);
	return c;
}


