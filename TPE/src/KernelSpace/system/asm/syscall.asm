GLOBAL 	_syscall_read
GLOBAL  _syscall_write
GLOBAL	_syscall_printidt
GLOBAL	_syscall_getbiosinfo
GLOBAL	_syscall_makesound
GLOBAL  _int_80_hand

EXTERN	int_80

SECTION .text
_syscall_makesound:
	push	ebp
	mov 	ebp,esp
	push	ebx
	push	ecx
	push	edx
	mov	eax,7
	mov	ebx,[ebp+8]
	mov	ecx,0
	mov	edx,[ebp+12]
	int 	80h
	pop	edx
	pop	ecx
	pop	ebx
	mov	esp,ebp
	pop	ebp
	ret

_syscall_getbiosinfo:
	push	ebp
	mov 	ebp,esp
	push	ebx
	push	ecx
	push	edx
	mov	eax,6
	mov	ebx,0
	mov	ecx,0
	mov	edx,0
	int 	80h
	pop	edx
	pop	ecx
	pop	ebx
	mov	esp,ebp
	pop	ebp
	ret
_syscall_printidt:
	push	ebp
	mov 	ebp,esp
	push	ebx
	push	ecx
	push	edx
	mov	eax,5
	mov	ebx,[ebp+8]
	mov	ecx,0
	mov	edx,0
	int 	80h
	pop	edx
	pop	ecx
	pop	ebx
	mov	esp,ebp
	pop	ebp
	ret

_syscall_read:
	push	ebp
	mov	ebp, esp	; Armo el stack
	push	ebx
	push	ecx
	push 	edx
	mov	eax, 2
	mov 	ebx, [ebp+8]	; file descriptor, 2do argumento
				; no pusheamos eax porque se pisa con los resultados de las int
	mov	ecx, [ebp+12]	; buffer, 3er argumento
	mov	edx, [ebp+16]	; cantidad, 4to parametro
	int	80h
	pop 	edx
	pop	ecx
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret

_syscall_write:
	push	ebp
	mov	ebp, esp	; Armo el stack
	push	ebx
	push	ecx
	push 	edx
	mov	eax,1
	mov 	ebx,[ebp+8]	; file descriptor, 2do argumento
				; no pusheamos eax porque se pisa con los resultados de las int
	mov	ecx, [ebp+12]	; buffer, 3er argumento
	mov	edx, [ebp+16]	; cantidad, 4to parametro
	int	80h
	pop 	edx
	pop	ecx
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret

_int_80_hand:				; Handler de INT 80 ( Syscall ) 
	push 	ebp
	mov 	ebp,esp
        push	edx
	push	ecx
	push	ebx
	push	eax              
        call    int_80  
        pop	eax
	pop	ebx
	pop	ecx
	pop	edx
	mov 	esp,ebp
	pop	ebp
        iret
