/***************************************************
  Keyboard.h
	
****************************************************/

// http://wiki.osdev.org/PS2_Keyboard
// Se saco teoria para complementar y algunos scancodes tipo 1
// key mapping sacado del TP de Federico Ramundo: github/framundo
// scancode basado en parte en el de ellos tambien

#include "keyboard.h"
#include "../../../include/defs.h"

uint key_mapping [LANG][87] = { {0,0x1b,'1','2',
'3','4','5','6','7','8','9','0','-','=','\b','\t','q','w',
'e','r','t','y','u','i','o','p','[',']','\n',0,'a','s',
'd','f','g','h','j','k','l',';','\'','\\',0,'\\','z','x',
'c','v','b','n','m',',','.','/','\\','.',56,' ',58,59,60,
61,62,63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
79, 80, 81, 82, 83, 84, 85, '<' }, { 0, 0xb3, '1', '2',
'3', '4', '5', '6', '7', '8', '9', '0', '\'', 0xa8, '\b', '\t', 'q',
'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',26, '+', '\n', 0, 'a',
's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 0xa4, '{', 0xb3, 0, '}', 'z',
'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', '\\', '.', 56, ' ', 58, 59,
60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
78, 79, 80, 81, 82, 83, 84, 85, '<' }};

uint key_mapping_shift [LANG][87] = {{ 0, 0x1b, '!', '@', '#', '$',
'%', '^','&', '*', '(', ')', '_', '+', '\b','\t', 'Q', 'W', 'E', 'R', 'T',
'Y', 'U','I', 'O', 'P', '{', '}', '\n',0, 'A', 'S', 'D', 'F', 'G', 'H', 'J',
'K', 'L', ':', '"', 0xb3, 0, '|','Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
'\\', '.', 56, ' ',58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
73, 74, 75,76, 77, 78, 79, 80, 81, 82, 83, 84, 85, '>' },{ 0, 0xa7, '!', '"',
'#', '$', '%', '&', '/', '(', ')', '=', '?', 0xad, '\b','\t', 'Q', 'W', 'E',
'R', 'T', 'Y', 'U', 'I', 'O', 'P', 26, '*', '\n',0, 'A', 'S', 'D', 'F', 'G',
'H', 'J', 'K', 'L', 0xa5, '[', 0xa7, 42,']', 'Z', 'X', 'C', 'V', 'B', 'N', 'M',
';', ':', '_', '\\', '.', 56,' ', 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
70, 71, 72, 73, 74,75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, '>' }};

byte keypad [13] = {'7','8','9','-','4','5','6','+','1','2','3','0','.'};

int shift=0,capslock=0,set=0,nlock=1; //set indica que se recibio un scancode set, estos arrancan con un 0xE0

int lang = 0;
char buffer[BUFFER_SIZE];
int tail=0;
int head=0;


int kisdigit(int c) {
	return (c <= '9' && c >= '0');
}
int kisupper(int c) {
	return (c <= 'Z' && c >= 'A');
}

int kislower(int c) {
	return (c <= 'z' && c >= 'a');
}
int ktoupper (int c) {
	if(kislower(c))
		return c - ('a'-'A');
	return c;
}

int ktolower (int c) {
	if(kisupper(c))
		return c + ('a'-'A');
	return c;
}

void scancode(char keycode) {
	char c=0;	
	if (released(keycode)) {
		if( keycode == SETFLAG ) 
			set=1;
		if( (keycode&0x7F)==RIGHT_SHIFT || (keycode&0x7F)==LEFT_SHIFT ){			
			shift=0;
			set=0;
		}
	} else {
		if( (keycode==RIGHT_SHIFT) || (keycode==LEFT_SHIFT) ){
			shift=1;
			set=0;
		} else {
			if(keycode==NUMBERLOCK)
				nlock=(nlock+1)%2;
			else {
				if(keycode==CAPSLOCK)
					capslock=(capslock+1)%2;
				else {
					if (keypad_key(keycode)) {
						char aux = keypad[keycode-0x47];
						if (kisdigit(aux) & !nlock)
							c=aux;
					} else {
						if(set) {
							if(keycode==BAR)
								c='/';
							if(keycode==ENTER)
								c='\n';
						}
						if (shift) {
							c=key_mapping_shift[lang][(int)keycode];
							if(capslock)
								c=ktolower(c);
						} else {
							c=key_mapping[lang][(int)keycode];
							if(capslock)
								c=ktoupper(c);		
						}
					}
					if (printable(keycode)||keypad_key(keycode)){
						buffer_putchar(c);
					set=0;
					}
				}
			}
		}
	}
	return;
}
void buffer_putchar(char c){
	buffer[tail++]=c;
	if(tail==BUFFER_SIZE){
		tail=0;
	}
}
char buffer_getchar(){
	if(head==tail){
		return 0;
		
	}
	char aux=buffer[head++];
	if(head==BUFFER_SIZE){
		head=0;
	}
	return aux;
}
int released (char keycode) {
	return ( keycode & 0x80 ) != 0;
}

int keypad_key(char keycode) {
	return ( keycode >= 0x47 && keycode <= 0x53);
}

int printable(byte c) {
	if ((c > 1 && c < 26) || (c > 29 && c < 42) || (c > 42 && c < 56) ||c==28 || c == 57 || c == 86) {
		return 1;
	}
	return 0;
}

