global _start

section .text
_start:
    mov     esi, 0
_loop:
    mov     al, byte [num_array + esi]
    add     eax, 0x30 ; ascii shift
    mov     byte [buffer + esi*2], al
    mov     byte [buffer + esi*2 + 1], 0x20
    inc     esi
    cmp     esi, arr_len
    jl      _loop

    mov     byte [buffer + buf_size - 1], 0xA

    mov     ecx, buffer
    mov     edx, buf_size
    mov     ebx, 0
    mov     eax, 4
    int     0x80

_exit:
    mov     ebx, 0
    mov     eax, 1
    int     0x80

section .data
    num_array  db    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    arr_len    equ   $ - num_array
    buf_size   equ   arr_len * 2 + 1

section .bss
    buffer     resb  buf_size