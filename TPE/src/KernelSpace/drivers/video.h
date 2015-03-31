#define WHITE_TXT 0x07 // Atributo de video. Letras blancas, fondo negro
#define RED_TXT 0x04
#define BLUE_TXT 0x01

/* Limpia la pantalla */
void setScreen(char color);
void k_clear_screen();
void kprint(int c);
int position(int pos_x, int pos_y);
void idtinfo();
void getBiosinfo();

