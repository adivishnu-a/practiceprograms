DATA SEGMENT            ; Define data segment
    ARRAY DB 5, 3, 8, 6, 2, 7, 1, 4, 9   ; Define an array of 9 bytes
    MSG DB "SORTED ARRAY = $"            ; Define a string message
DATA ENDS

CODE SEGMENT            ; Define code segment
ASSUME CS:CODE, DS:DATA

; Start of program
START:
    MOV AX, DATA        ; Move the starting address of data segment to AX register
    MOV DS, AX          ; Move the starting address of data segment to DS register
    MOV CL, 8           ; Set the counter to 8 (the number of elements in the array)

OUTER_LOOP:
    MOV CH, CL          ; Move the value of CL to CH register
    MOV SI, 0           ; Initialize the index to the first element

INNER_LOOP:
    MOV BX, SI          ; Move the value of SI to BX register
    INC BX              ; Increment BX by 1
    MOV AL, ARRAY[SI]   ; Move the value of the element at index SI to AL register
    CMP AL, ARRAY[BX]   ; Compare the values of the element at index SI and BX
    JNZ NOT_SORTED      ; Jump to NOT_SORTED if the values are not equal
    JMP NEXT_1          ; Jump to NEXT_1 if the values are equal

NOT_SORTED:
    JLE NEXT_1          ; Jump to NEXT_1 if AL is less than or equal to the element at index BX
    MOV AH, AL
    MOV AL, ARRAY[BX]
    MOV ARRAY[BX], AH
    MOV ARRAY[SI], AL   ; Move the value of AL to the element at index SI

NEXT_1:
    INC SI              ; Increment SI by 1
    DEC CH              ; Decrement CH by 1
    JNZ INNER_LOOP      ; Jump to INNER_LOOP if CH is not zero
    DEC CL              ; Decrement CL by 1
    JNZ OUTER_LOOP      ; Jump to OUTER_LOOP if CL is not zero
    
    MOV AH, 9           ; Set the function code for displaying a string
    LEA DX, MSG         ; Load the offset address of the message to DX register
    INT 21H             ; Display the message using DOS interrupt 21H
    
    MOV CX, 9           ; Set the counter to 9 (the number of elements in the array)
    DEC CX              ; Decrement CX by 1
    MOV SI, 0           ; Initialize the index to the first element
       
    MOV DL, ARRAY[SI]   ; Move the value of the element at index SI to DL register
    ADD DL, 30H         ; Convert the value to ASCII code
    MOV AH, 2           ; Set the function code for displaying a character
    INT 21H             ; Display the character using DOS interrupt 21H
    
PRINT_LOOP:
    MOV DL, ','         ; Move the ASCII code of comma to DL register
    MOV AH, 2           ; Set the function code for displaying a character
    INT 21H             ; Display the character using DOS interrupt 21H
    INC SI              ; Increment SI by 1
    MOV DL, ARRAY[SI]   ; Move the value of the element at index SI to DL register
    ADD DL, 30H         ; Convert the value to ASCII code
    MOV AH, 2           ; Set the function code for displaying a character
    INT 21H             ; Display the character using DOS interrupt 21H
    LOOP PRINT_LOOP     ; Loop for printing the sorted array
CODE ENDS               ; End of Code Segment
END START
