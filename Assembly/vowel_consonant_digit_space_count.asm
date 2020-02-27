INCLUDE 'EMU8086.INC'

.MODEL SMALL
.STACK 100H
.DATA
    MSG DB 80 DUP (?)
    VOWEL DB ?
    CONSONANT DB ?
    DIGITS DB ?
    SPACE DB ?
.CODE
MAIN PROC
    
        
    MOV AX,@DATA
    MOV DS,AX 
    MOV VOWEL,0
    MOV CONSONANT,0
    MOV DIGITS,0
    MOV SPACE,0  
    
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
        
        JMP CHECK_LETTER
        
        
    ELSEIF:
        CMP AL,'a'
        JL ELSEIF_DIGIT 
        CMP AL,'z'
        JG ELSEIF_DIGIT
        JMP CHECK_LETTER  
        
        CHECK_LETTER:
            CMP AL,'A'
            JE VOWEL_C 
            CMP AL,'E'
            JE VOWEL_C
            CMP AL,'I'
            JE VOWEL_C 
            CMP AL,'O'
            JE VOWEL_C
            CMP AL,'U'
            JE VOWEL_C 
            
            INC CONSONANT
            JMP LAST
    
        VOWEL_C: 
            INC VOWEL
        
    ELSEIF_DIGIT: 
        CMP AL,'0'
        JL SPACE_C
        CMP AL,'9'
        JG SPACE_C
        
        INC DIGITS
        JMP LAST 
        
    SPACE_C:
        CMP AL,' '
        JE SPACE_COUNT
        JMP LAST
    SPACE_COUNT:
        INC SPACE
        
    LAST:
    MOV [SI],AL
    INC SI
    LOOP READ 
    

WRITE:  

    CALL NEWLINE
   
    PRINT "NUMBER OF VOWEL : "
    MOV AH,2
    MOV DL,VOWEL
    ADD DL,'0'
    INT 21H
    
    CALL NEWLINE
    PRINT "NUMBER OF CONSONANT : "
    MOV AH,2
    MOV DL,CONSONANT
    ADD DL,'0'
    INT 21H
           
    CALL NEWLINE
    PRINT "NUMBER OF DIGITS : "
    MOV AH,2
    MOV DL,DIGITS
    ADD DL,'0'
    INT 21H
    
    CALL NEWLINE
    PRINT "NUMBER OF SPACE : "
    MOV AH,2
    MOV DL,SPACE
    ADD DL,'0'
    INT 21H
    
    MOV AX,4CH
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