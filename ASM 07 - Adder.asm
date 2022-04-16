global _start

section .text
_start:
        call  f_sys_read
        call  f_read_num
        push    dword [value]
        call  f_sys_read
        call  f_read_num

        pop     eax
        add     eax, [value]

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
_bin2txt:
        xor     edx, edx
        mov     ebx, 10
        div     ebx
        add     edx, 48
        push    edx
        cmp     eax, 0
        jg     _bin2txt
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

f_read_num:
        pusha
        mov     esi, 0
        xor     eax, eax
        mov     ecx, esp
_txt2bin:
        mov     al, byte [buffer + esi]
        cmp     eax, 48
        jl     _not_a_num
        cmp     eax, 57
        jg     _not_a_num
        sub     eax, 48
        push    eax
_not_a_num:
        inc     esi
        cmp     esi, 32
        jl    _txt2bin

        mov     ebx, 1
        mov     dword [value], 0
_arr2int:
        pop     eax
        mul     ebx
        add     [value], eax
        mov     eax, ebx
        mov     ebx, 10
        mul     ebx
        mov     ebx, eax
        cmp     ecx, esp
        jne     _arr2int

        popa
        ret

f_sys_read:
        mov     edx, 16
        mov     ecx, buffer
        mov     ebx, 0
        mov     eax, 3
        int     0x80
        ret

section .data
        value: dd 0x0

section .bss
        buffer: resb 32
