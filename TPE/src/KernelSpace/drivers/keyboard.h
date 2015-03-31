/***************************************************
  Keyboard.h
	
****************************************************/

#define BUFFER_SIZE 15

#define RIGHT_SHIFT 0x36
#define LEFT_SHIFT 0x2A
#define CAPSLOCK 0x3A
#define NUMBERLOCK 0x45

#define SETFLAG 0xE0

#define ESCAPE 0x01
#define TAB 0x0F
#define CTRL 0x1D //ALT y CTRL derechos reciben un 0xE0 antes
#define ALT 0x38

#define ENTER 0x1C
#define BAR 0x35
#define KEYS 87
#define LANG 2
#define STATES 2
#define ESP 0
#define ENG 1
#define SHIFT 2

void scancode(char keycode);
int released (char keycode);
int keypad_key(char keycode);
int printable(unsigned char c);
void buffer_putchar(char c);
char buffer_getchar();
