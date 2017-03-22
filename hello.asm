segment .data

    msg db "Hello, Layer7!",10,0

segment .text

global _start

_start:
    mov rax,1
    mov rdi,1
    mov rsi,msg
    mov rdx,15
    syscall

    mov rax,60
    xor rdi,rdi
    syscall


    




