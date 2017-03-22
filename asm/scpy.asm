.text
.globl _strcpy

_strcpy:
    mov esi,dword ptr [esp+8]
    mov edi,dword ptr [esp+4]
loop:
    movsb
    cmpb edi,#0
    je end
    je loop
end:
    ret
