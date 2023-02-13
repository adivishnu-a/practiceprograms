
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

; The easiest way to print out "Hello, World!"

name "hi"

org 100h

jmp start       ; jump over data declaration

msg:    db      "Hello, World!", 0Dh,0Ah, 24h

start:  mov     dx, msg  ; load offset of msg into dx.
        mov     ah, 09h  ; print function is 9.
        int     21h      ; do it!
        
        mov     ah, 0 
        int     16h      ; wait for any key....
        
ret ; return to operating system.

ret




