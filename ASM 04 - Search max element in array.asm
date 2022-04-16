global _start

section .text
_start:
        xor     esi, esi
        xor     eax, eax
_loop:
        cmp     ax, word [num_array + esi*2]
        jge     _skip

        mov     ax, word [num_array + esi*2]
        mov     ebx, esi
        add     ebx, 0x30
        mov     byte [buffer], bl
_skip:
        inc     esi
        cmp     esi, arr_len
        jl   _loop

        mov     byte [buffer+1], 0xA
; print
        mov     edx, 2
        mov     ecx, buffer
        mov     ebx, 0
        mov     eax, 4
        int     0x80
; exit
        mov     eax, 1
        mov     ebx, 0
        int     0x80

section .data
        num_array dw 32, 1, 56, 1997, 8, 0, 107, 34, 56, 1997
        arr_len equ $ - num_array
section .bss
        buffer resb 2