INCLUDE 'EMU8086.INC'

.MODEL SMALL
.STACK 100H
.DATA
    RESULT DB ?
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ;INPUT
    PRINT "TAKE INPUT FORM 0 TO 3 : "
    MOV AH,01H
    INT 21H 
    
    
    ;LOOP 
    SUB AL,'0' ;Character to decimal
    MOV CL,AL  ;counter register set value
    MOV AL,1
    CMP CL,0
    JE IFZERO  
    L1:      
       MUL CL
       DEC CL   
       JNZ L1

IFZERO:
    ADD AL,'0' ;decimal to character
    MOV RESULT,AL
       
    ;new line print
    MOV AH,02H
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    
    ;OUTPUT
    PRINT "FACTORIAL SUM : " 
    
    MOV DL,RESULT
    MOV AH,2
    INT 21H
    
    
    MOV AX,4CH
    INT 21H
MAIN ENDP
END MAIN