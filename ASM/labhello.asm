
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

    mov dx, offset msg
    mov ah, 9h
    int 21h

ret

msg db "Hello World!$"


