INCLUDE 'EMU8086.INC'

.MODEL SMALL
.STACK 100H
.DATA
    MSG DB 80 DUP (?)
    NEW_LINE DB 10,13,'$'
    
.CODE
MAIN PROC
    
        
    MOV AX,@DATA
    MOV DS,AX 
    
    PRINT "TAKE INPUT : "
    LEA SI,MSG
READ:
    MOV AH,01H
    INT 21H
    CMP AL,13
    JE WRITE
    
    IF:
        CMP AL,'A'
        JL ELSEIF
        CMP AL,'Z'
        JG ELSEIF
        ADD AL,32
        JMP ELSE
        
    ELSEIF:
        CMP AL,'a'
        JL ELSE 
        CMP AL,'z'
        JG ELSE
        SUB AL,32
    
    ELSE:
    MOV [SI],AL
    INC SI
    LOOP READ 
    

WRITE:  

    LEA DX,NEW_LINE
    MOV AH,09H
    INT 21H
    PRINT "OUTPUT STRING : "
 
    
    
    LEA DX,MSG
    MOV AH,09H
    INT 21H
    
    MOV AX,4CH
    INT 21H
MAIN ENDP
END MAIN