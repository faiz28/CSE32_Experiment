INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
    MSG DB 80 DUP (?) 
    MSG2 DB 80 DUP (?)
    N DB ?
    SIZE DW ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
        
    MOV SI,500
    MOV SIZE,0 
    
    PRINT "TAKE STRING INPUT : "
    
    READ:
        MOV AH,1
        INT 21H
        CMP AL,13  ;Untile newline  enter
        JE OUTPUT
        
        MOV MSG[SI],AL
        INC SI
        INC SIZE
        JMP READ
    OUTPUT:
        CALL NEWLINE
        PRINT "REVERSE STRING : "
        MOV SI,500
        ADD SI,SIZE
        
        WRITE: 
            CMP SI,500
            JL ENDWRITE
            MOV AH,2
            MOV DL,MSG[SI]
            INT 21H  
            DEC SI
            JMP WRITE
        ENDWRITE:
    
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
        
