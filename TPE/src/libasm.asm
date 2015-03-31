GLOBAL  _read_msw,_lidt
GLOBAL  _Cli,_Sti
GLOBAL  _debug
GLOBAL 	_createsound

EXTERN tick_wait

SECTION .text


_createsound:
	push 	ebp
	mov	ebp,esp
	push 	ax
	push 	bx
	push 	ecx
	mov	ecx, [ebp+12] 	;cantidad de ciclos
	push	ecx
	mov 	bx, [ebp+8]	;frecuencia
	mov	al, 10110110B	
	out	43h,al		;inicializa el puerto 43h
	mov	ax, bx
	out	42h,al		;se envia la frecuencia deseada al Timer 2
	mov	al,AH		;es de 8 bits por lo que debemos enviarla en 2 pasadas
	out	42h,al
	in	al,61h		;prepara al speaker para recibir pulsos. Se deben cambiar 
	or	al,00000011B	;los ultimos dos bits en 1 
	out	61h,al	
	sti	
	call	tick_wait	
	in	al,61h
	and	al,11111100B	;vuelve al speaker al estado OFF poniendo los ultimos dos
	out	61h,al		;bits en 0
	pop	ecx
	pop	ecx
	pop	bx
	pop	ax
	mov	esp, ebp
	pop	ebp
	ret
		

_Cli:
	cli			; limpia flag de interrupciones
	ret

_Sti:

	sti			; habilita interrupciones por flag
	ret

_read_msw:
        smsw    ax		; Obtiene la Machine Status Word
        retn

_lidt:				; Carga el IDTR
        push    ebp
        mov     ebp, esp
        push    ebx
        mov     ebx, [ss: ebp + 6] ; ds:bx = puntero a IDTR 
	rol	ebx,16		    	
	lidt    [ds: ebx]          ; carga IDTR
        pop     ebx
        pop     ebp
        retn


; Debug para el BOCHS, detiene la ejecución; Para continuar colocar en el BOCHSDBG: set $eax=0
;


_debug:
        push    bp
        mov     bp, sp
        push	ax
vuelve:	mov     ax, 1
        cmp	ax, 0
	jne	vuelve
	pop	ax
	pop     bp
        retn

	
