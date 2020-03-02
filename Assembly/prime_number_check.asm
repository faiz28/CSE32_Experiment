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
    MOV AH,1  ;String Input
    INT 21H
    
    SUB AL,'0' ;char to digit convert
    MOV N,AL
    MOV DIVISOR,AL
    
    CMP AL,1
    JLE NOT_PRIME   ;if less then equal 1 not prime
    
    DEC DIVISOR

    
    FOR:
        MOV AH,0  
        CMP DIVISOR,1
        JE PRIME
        
        DIV DIVISOR  ; AL/DIVISOR then AL contine quotient and AH contine remainder
        
        CMP AH,0
        JE NOT_PRIME  ;if remainder==0 then not prime
        
        MOV AL,N      ;update AL register to N 
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
