GLOBAL  _remapPIC	;Mapeo del pic
GLOBAL  _mascaraPIC1,_mascaraPIC2

GLOBAL	_int_08_hand	;Handler Interrupciones
GLOBAL  _int_09_hand
GLOBAL  _int_10_hand

EXTERN  int_08
EXTERN  int_09

SECTION .text

_mascaraPIC1:			; Escribe mascara del PIC 1
	push    ebp
        mov     ebp, esp
        mov     ax, [ss:ebp+8]  ; ax = mascara de 16 bits
        out	21h,al
        pop     ebp
        retn

_mascaraPIC2:			; Escribe mascara del PIC 2
	push    ebp
        mov     ebp, esp
        mov     ax, [ss:ebp+8]  ; ax = mascara de 16 bits
        out	0A1h,al
        pop     ebp
        retn
	
; **************************************************************
; * Codigo basado de https://wiki.osdev.org/PIC#Initialisation * 
; **************************************************************

_remapPIC:			
	push 	ax
	in 	al, 20h		; Guardo la mascara del PIC1
	push	ax
	in	al, 0A0h		; Guardo la mascara del pIC2
	push 	ax
	mov 	al, 10h
	out 	20h, al		; Comienza la secuencia de inicializacion (en modo cascada)
	out	0A0h, al
	mov 	al, 20h
	out 	21h, al		; Cargo el offset nuevo del PIC1 mandando a la posicion 32 de la IDT
	mov	al, 28h
	out	0A1h, al 	; Cargo el offset nuevo del PIC2 mandando a la posicion 40 de la IDT
	mov 	al, 4
	out 	21h, al		; Le dice al PIC1 que PIC2 esta en el IRQ2 (0000 0100)
	mov 	al, 2
	out 	21h, al		; Le dice al PIC2 su cascade identity (0000 0100)
	pop 	ax
	out	0A1h, al 	; Restituyo la mascara del PIC2	
	pop	ax
	out 	21h, al		; Restituyo la mascara del PIC1
	pop 	ax
	retn

_int_08_hand:				; Handler de INT 8 ( Timer tick )
        push    ds
        push    es                      ; Se salvan los registros
        pusha                           ; Carga de DS y ES con el valor del selector
        mov     ax, 10h			; a utilizar.
        mov     ds, ax
        mov     es, ax                  
        call    int_08                 
        mov	al,20h			; Envio de EOI generico al PIC
	out	20h,al
	popa                            
        pop     es
        pop     ds
        iret

_int_09_hand:
	push    ds
        push    es                      ; Se salvan los registros
        push	ax                      ; Carga de DS y ES con el valor del selector
        mov     ax, 10h			; a utilizar.
        mov     ds, ax
        mov     es, ax
	in	al, 60h
	push	ax       
        call    int_09
        mov	al,20h			; Envio de EOI generico al PIC
	out	20h,al
	pop	ax
	pop	ax
	pop 	es
	pop	ds
	iret
