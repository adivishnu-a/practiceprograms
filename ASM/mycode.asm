DATA SEGMENT
    STR DB 'HELLO WORLD$'  
    VOWEL_COUNT DB 0      
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA      
    MOV DS, AX        

    MOV CX, 0         
    MOV SI, 0         

COUNT_LOOP:
    MOV AL, STR[SI]   
    CMP AL, '$'       
    JE END_PROGRAM   
    CMP AL, 'A'     
    JE INCREMENT      
    CMP AL, 'E'        
    JE INCREMENT      
    CMP AL, 'I'        
    JE INCREMENT      
    CMP AL, 'O'       
    JE INCREMENT     
    CMP AL, 'U'       
    JE INCREMENT      

INCREMENT:
    INC VOWEL_COUNT   
    INC SI            
    JMP COUNT_LOOP   

END_PROGRAM:
    MOV AH, 2         
    MOV AL, VOWEL_COUNT 
    ADD AL, 48         
    MOV DL, AL
    INT 21H           
    MOV AH, 4CH       
    INT 21H           

CODE ENDS
END START
