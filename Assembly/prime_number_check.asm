INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
    DIVISOR DB ?
    N DB ?
.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    PRINT "TAKE INPUT FROM 0 TO 9"
    MOV AH,1
    INT 21H
    
    SUB AL,'0'
    MOV N,AL
    MOV DIVISOR,AL
    
    CMP AL,1
    JLE NOT_PRIME
    
    DEC DIVISOR
    
    FOR:
        MOV AH,0
        CMP DIVISOR,1
        JE PRIME
        
        DIV DIVISOR
        
        CMP AH,0
        JE NOT_PRIME
        
        MOV AL,N
        DEC DIVISOR
        
        JMP FOR
        
    PRIME:    
        CALL NEWLINE
        PRINT "IT IS PRIME NUMBER"
        JMP EXIT
    NOT_PRIME:
        CALL NEWLINE
        PRINT "IT IS NOT PRIME NUMBER"
        JMP EXIT
        
    EXIT:
        MOV AH,4CH
        INT 21H     
    MAIN ENDP
    NEWLINE PROC
        MOV AH,2
        MOV DL,10
        INT 21H
        MOV DL,13
        INT 21H
        RET
    NEWLINE ENDP
END MAIN