GLOBAL  _exc_00_hand	;Handler Excepciones
GLOBAL	_exc_01_hand
GLOBAL	_exc_02_hand
GLOBAL  _exc_03_hand	
GLOBAL	_exc_04_hand
GLOBAL	_exc_05_hand
GLOBAL  _exc_06_hand	
GLOBAL	_exc_07_hand
GLOBAL	_exc_08_hand
GLOBAL  _exc_09_hand	
GLOBAL	_exc_0A_hand
GLOBAL	_exc_0B_hand
GLOBAL	_exc_08_hand
GLOBAL  _exc_09_hand	
GLOBAL	_exc_0A_hand
GLOBAL	_exc_0B_hand
GLOBAL	_exc_0C_hand
GLOBAL  _exc_0D_hand	
GLOBAL	_exc_0E_hand
GLOBAL	_exc_0F_hand
GLOBAL	_exc_10_hand
GLOBAL  _exc_11_hand	
GLOBAL	_exc_12_hand
GLOBAL	_exc_13_hand

EXTERN  exc

SECTION .text
_exc_00_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 0
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_01_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 1
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_02_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 2
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_03_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 3
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_04_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 4
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_05_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 5
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_06_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 6
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_07_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 7
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_08_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 8
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_09_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 9
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_0A_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 10
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_0B_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 11
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_0C_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 12
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_0D_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 13
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_0E_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 14
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_10_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 16
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_11_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 17
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_12_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 18
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

_exc_13_hand:
	push 	ebp
	mov 	ebp, esp
	mov 	eax, 19
	push	eax
	call 	exc
	mov	esp, ebp
	pop	ebp
	mov	esp, ebp
	pop	ebp
	sti
	ret

