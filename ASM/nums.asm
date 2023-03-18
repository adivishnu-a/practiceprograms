ORG 100h 
.DATA
  a db  0,1,2,3,4,5,6,7,8,9
.CODE 
    MOV CX,10
    MOV SI,0
    LOOP1:
    MOV AL, a[SI]
    MOV DL, AL
    ADD DL, 48
    MOV AH, 2h
    INT 21h
    INC SI
    LOOP LOOP1
    HLT
