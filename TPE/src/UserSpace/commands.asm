
GLOBAL	_zerodiv
GLOBAL  _invalidOpcode
GLOBAL	_debugtest

_zerodiv:	
	mov 	ax, 0
	div	ax
	ret

_invalidOpcode:
	mov	cs, ax

_debugtest:
	pushf
	pop eax
	or eax, 100h
	push eax
	popf
	jmp _debugtest
