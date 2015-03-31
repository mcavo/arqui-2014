#include "video.h"
#include "../../kernel.h"
#include "../../../include/defs.h"
#include "../system/bios.h"
#define WIDTH 80
#define HEIGHT 25



/***************************************************************
*k_clear_screen
*
* Borra la pantalla en modo texto color.
****************************************************************/
char *vidmem = (char *) 0xb8000;
int cursor_x = 0;
int cursor_y = 0; 
char screen = WHITE_TXT;

void setScreen(char color) {
	screen = color;
}

void k_clear_screen() {	
	unsigned int i=0;
	while(i < (WIDTH*HEIGHT*2))
	{
		vidmem[i]=' ';
		i++;
		vidmem[i]=screen;
		i++;
	};
}
void scroll(){
	int i;
	for(i=0;i<23*80*2;i++){
		vidmem[i]=vidmem[i+320];
	}
	while(i<26*80*2){
		vidmem[i++]=' ';
		vidmem[i++]=screen;
	}
	cursor_y-=2;
}
void kprint(int c){
	switch(c) {
		case '\n':
			cursor_x=0;
			cursor_y++; 
			break;
		case '\b':
			if(cursor_x==0) {
				if(cursor_y==0){
				}
				else{
					cursor_x=WIDTH-1;
					cursor_y--;
				}
			} else {
				cursor_x--;
			} 
			vidmem[position(cursor_x,cursor_y)]=' ';
			vidmem[position(cursor_x,cursor_y)+1]=screen;
			break;
		case '\t':
			cursor_x+=(4-cursor_x%4);
			if(cursor_x>WIDTH-1){
				cursor_x=0;
				cursor_y++;
			}
			break;
		case 0:
			break;	
		default:
			vidmem[position(cursor_x,cursor_y)]=c;
			vidmem[position(cursor_x,cursor_y)+1]=screen;
			if(cursor_x==(WIDTH-1)) {
				cursor_x=0;
				cursor_y++;
			} else {
				cursor_x++;
			} 
	}
	if(cursor_y==25){
		scroll();
	}
}

void ksprint(char* string){
	int i;
	for(i=0;string[i]!='\0';i++){
		kprint((int)string[i]);
	}
}
void kstrrev( char* s ) {
	int dim = 0, i=0;
	char aux;
	for (i=0; s[i]!=0;i++){
		dim++;
	}
	for (i=0; i<dim/2 ;i++) {
		aux=*(s+i);
		s[i]=s[dim-1-i];
		s[dim-1-i]=aux;
	}
}

void kxtoa(int n,char* s) {
	int i=0,rem;
    	while (n!=0)
    	{
        	rem=n%16;
        	switch(rem)
        	{
		    case 10:
			      s[i]='A';
			      break;
		    case 11:
			      s[i]='B';
			      break;
		    case 12:
			      s[i]='C';
			      break;
		    case 13:
			      s[i]='D';
			      break;
		    case 14:
			      s[i]='E';
			      break;
		    case 15:
			      s[i]='F';
		              break;
		    default:
		      	      s[i]=rem+'0';
			      break;
		}
		++i;
		n/=16;
	}
	s[i]='\0';
	kstrrev(s); 
}

void khprint(int num){
	char* hexa=0;
	int i=0;
	int ceros=0;
	kxtoa(num,hexa);
	while(hexa[i]!='\0'){
		i++;
	}
	ceros=8-i;
	while(ceros!=0){
		kprint('0');
		ceros--;
	}
	ksprint(hexa);
	kprint('h');
}
int position(int pos_x, int pos_y) {
	return 2*(pos_y*WIDTH+pos_x);	
}

void idtinfo(){
	int IDT_size = idtr.limit/8;
	int i;
	int posicion;
	int offset;
	ksprint("                  Entry      Selector      Offset       Access \n");
	for(i=0;i<=IDT_size;i++){
		if(idt[i].selector==0){
		}
		else{
			posicion=idtr.base+i;
			ksprint("  ");
			khprint(posicion);
			ksprint(":    ");
			khprint(i);
			ksprint("    ");
			khprint(idt[i].selector);
			offset=(idt[i].offset_h<<16)+idt[i].offset_l;
			ksprint("    ");
			khprint(offset);
			ksprint("    ");
			khprint(idt[i].access);
			kprint('\n');
		}
	}
}

void getBiosinfo(){
	byte ** info;
	getBIOS(&info);
	ksprint("\n  **************************\n");
	ksprint("  *    BIOS Information    *\n");
	ksprint("  **************************\n\n");
	ksprint("   Vendor:     ");
	ksprint((char *)*info);
	kprint('\n');
	ksprint("   Version:    ");
	ksprint((char *)*(info+1));
	kprint('\n');
	ksprint("   Date:       ");
	ksprint((char *)*(info+2));
	kprint('\n');
}
