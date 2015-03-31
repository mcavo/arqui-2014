/*********************************************
kasm.h

************************************************/

#include "../../../kernel.h"


unsigned int    _read_msw();
void		_syscall_write(int fd, const void* buffer, size_t count);
void 		_syscall_read(int fd,const void* buffer, size_t count);
void		_syscall_getbiosinfo(int fd);
void		_syscall_makesound(int fre,int cycle);

void            _lidt (IDTR *idtr);
void		_syscall_printidt(int fd);
void		_mascaraPIC1 (byte mascara);  /* Escribe mascara de PIC1 */
void		_mascaraPIC2 (byte mascara);  /* Escribe mascara de PIC2 */
void		_remapPIC (void);  /* Redirecciona el PIC1 para que no haya conflicto con las excepciones */
void		_createsound(int f, int cycles);

void		_Cli(void);        /* Deshabilita interrupciones  */
void		_Sti(void);	 /* Habilita interrupciones  */

void		_exc_00_hand();      /* Exception: Divide by zero */
void		_exc_01_hand();      /* Exception: Debug */
void		_exc_02_hand();      /* Exception: NMI */
void		_exc_03_hand();      /* Exception: Breakpoint */
void		_exc_04_hand();      /* Exception: Overflow */
void		_exc_05_hand();      /* Exception: Bound range exceeded */
void		_exc_06_hand();      /* Exception: Invalid opcode */
void		_exc_07_hand();      /* Exception: Device not available */
void		_exc_08_hand();      /* Exception: Double fault */
void		_exc_09_hand();      /* Exception: Coprocessor segment overrun */
void		_exc_0A_hand();      /* Exception: Invalid TSS */
void		_exc_0B_hand();      /* Exception: Segment not present */
void		_exc_0C_hand();      /* Exception: Stack-segment fault */
void		_exc_0D_hand();      /* Exception: General Protection */
void		_exc_0E_hand();      /* Exception: Page fault */
void		_exc_10_hand();      /* Exception: x87 FPU floating-point error */
void		_exc_11_hand();      /* Exception: Alignment check */
void		_exc_12_hand();      /* Exception: Machine check */
void		_exc_13_hand();      /* Exception: SIMD floating-point */

void		_int_08_hand();      /* Timer tick */
void		_int_09_hand();	    	 /* KeyBoard */
void		_int_80_hand(int fd, const void* buffer, size_t count);

void		_debug (void);


