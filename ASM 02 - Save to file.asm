buf_size  equ  1024

global _start
section .text
_start:
    mov     edx, buf_size
    mov     ecx, buffer
    mov     ebx, 1        ; cin
    mov     eax, 3        ; sys_read(descriptor, buffer, size)
    int     0x80

    mov     edx, 0
    mov     ecx, 1        ; writeonly
    mov     ebx, filename
    mov     eax, 5        ; sys_open(filename, flag, mode) -> descriptor 
    int     0x80
    cmp     eax, 0
    jl      createfile

writetofile:
    mov     edx, buf_size
    mov     ecx, buffer
    mov     ebx, eax
    mov     eax, 4        ; sys_write(descriptor, buffer, size)
    int     0x80

    mov     eax, 6        ; sys_close(descriptor)
    int     0x80

exit:
    mov     ebx, 0
    mov     eax, 1        ; sys_exit(result)
    int     0x80

createfile:
    mov     ecx, 0755o    ; rwx r-x r-x
    mov     ebx, filename
    mov     eax, 8        ; sys_creat(pathname, mode)
    int     0x80
    cmp     eax, 0
    jl      exit
    jmp     writetofile
   

section .data
    filename db './my-file.txt', 0x0

section .bss
    buffer: resb buf_size