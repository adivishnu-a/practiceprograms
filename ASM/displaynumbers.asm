org 100h
.data
a db 0,1,2,3,4,5,6,7,8,9
.code
mov cx,10
mov si,0
loop1:
mov al,a[si]
mov dl,al
add dl,48
mov ah,2h
int 21h
INC si
loop loop1
Hlt