global _start
section .text
_start:
        mov     ecx, ' '
_loop:
        cmp     ecx, '~'
        jg     _exit
        mov     eax, ecx
        call  f_print_number
        mov     [buf], cl
        call  f_print_buffer
        inc     ecx
        jmp    _loop

_exit:
        mov     ebx, 0
        mov     eax, 1
        int     0x80

f_print_buffer:
        pusha
        mov     edx, 3
        mov     ecx, sep
        call  f_print_str
        mov     edx, 2
        mov     ecx, buf
        call  f_print_str
        popa
        ret

f_print_number: ; eax - number
        pusha
        mov     ecx, esp
        xor     edx, edx
        mov     ebx, 10
_conv_and_push:
        div     bl
        mov     dl, ah
        add     edx, 0x30
        push    edx
        mov     ah, 0
        cmp     al, 0
        jg     _conv_and_push
_pop_and_print:
        pop     eax
        mov     [buf], al
        push    ecx
        mov     edx, 1
        mov     ecx, buf
        call  f_print_str
        pop     ecx
        cmp     ecx, esp
        jne    _pop_and_print
        popa

f_print_str: ; edx - size, ecx -- ptr
        pusha
        mov     eax, 4
        mov     ebx, 1
        int     0x80
        popa
        ret

section .data
        sep:    db      " - "
        buf:    db      0x00, 0x0A