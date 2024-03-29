DATA SEGMENT
    PWD DB 'ABCDEF$'
    INP DB 'ABCDEF$'
    MATCHED DB 'Y$'
    NOMATCH DB 'N$'
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX

    MOV SI, 0
    MOV DI, 0

CHECK_LOOP:
    MOV AL, PWD[SI]
    MOV BL, INP[DI]
    CMP AL, BL
    JNE NOT_SAME

    INC SI
    INC DI
    CMP AL, '$'
    JNE CHECK_LOOP

    MOV AH, 9
    LEA DX, MSG_Y
    INT 21H
    JMP END_PROGRAM

NOT_SAME:
    MOV AH, 9
    LEA DX, NOMATCH
    INT 21H
    JMP END_PROGRAM

END_PROGRAM:
    MOV AH, 4CH
    INT 21H

CODE ENDS
END START
