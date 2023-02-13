
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.model small

.data
msg db "Hello World !!$"

.code
mov ax, @data
mov ds, ax

lea dx, msg
mov ah, 09h
int 21h

mov ah, 4ch
int 21h
end

ret




                                                                                                           
                                                                                                           
                                                                                                           