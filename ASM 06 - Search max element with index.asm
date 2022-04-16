global _start

section .text
_start:
        xor     eax, eax
        xor     ebx, ebx
        xor     ecx, ecx
        xor     edx, edx
_loop:
        cmp     ecx, len
        jge    _break
        cmp     ax, word [num_array + ecx*2]
        jg     _skipall
        je     _skip
        mov     ax, word [num_array + ecx*2] ; value
        mov     ebx, ecx ; index
        xor     edx, edx ; times
_skip:
        inc     edx
_skipall:
        inc     ecx
        jmp _loop
_break:
        ; print result
        call  f_print_num
        cmp     edx, 2
        jl     _exit
        mov     eax, ebx
        call  f_print_num

_exit:
        mov     eax, 1
        mov     ebx, 0
        int     0x80

f_print_num:
        pusha
        mov     edi, esp
        mov     edx, 10 ; '\n'
        push    edx
_conv:
        xor     edx, edx
        mov     ebx, 10
        div     ebx
        add     edx, 48
        push    edx
        cmp     eax, 0
        jg     _conv
_print:
        mov     edx, 4
        mov     ecx, esp
        mov     ebx, 1
        mov     eax, 4
        int     0x80

        pop     eax
        cmp     edi, esp
        jne    _print

        popa
        ret

section .data
        num_array dw 31, 1, 56, 1997, 8, 0, 107, 34, 56, 1997
        len equ $ - num_array