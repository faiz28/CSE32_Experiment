INCLUDE 'EMU8086.INC'
.MODEL SMALL
.DATA
    ARR DB 80 DUP (?)
    N DB ?
    M DB ?
    SIZE DB ?
    MIN DB ?
    MAX DB ? 
    POS DW ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
  
    MOV SIZE,0
    MOV SI,500
    INPUT:
        MOV AH,1   
        INT 21H
        CMP AL,13
        JE OUTPUT 
        MOV ARR[SI],AL
        INC SI
        INC SIZE
        JMP INPUT
        
    OUTPUT:  
        CALL ASORT  
        CALL NEWLINE
        PRINT "ASENDING ORDER SORT : "
        MOV SI,500
        MOV N,0
        
        L1:   
            MOV AL,N
            CMP AL,SIZE
            JE ENDOUTPUT
            MOV AH,2
            MOV DL,ARR[SI]
            INT 21H
            INC SI 
            INC N 
            JMP L1
    ENDOUTPUT:
     
        CALL DSORT 
        CALL NEWLINE 
        PRINT "DESENDING ORDER SORT : "
        MOV SI,500
        MOV N,0
        
        L2:   
            MOV AL,N
            CMP AL,SIZE
            JE ENDOUTPUT_DEC
            MOV AH,2
            MOV DL,ARR[SI]
            INT 21H
            INC SI 
            INC N 
            JMP L2
    ENDOUTPUT_DEC:
        MOV AH,4CH
        INT 21H
MAIN ENDP

ASORT PROC
      
      MOV SI,500
      MOV N,0
      
      AFOR:
        MOV AL,N
        CMP AL,SIZE
        JE END_AFOR
        
        MOV DI,SI
        MOV M,AL
        INC DI 
        INC M
        MOV POS,SI
        MOV BL,ARR[SI]  
        MOV MIN,BL 
        
        
        ANFOR:
            MOV BL,M
            CMP BL,SIZE
            JE ANFOR_END  
            
            MOV AL,ARR[DI]
            CMP AL,MIN
            JL NEWMIN
            JMP CONT
            
            NEWMIN:
                MOV BL,ARR[DI]
                MOV MIN,BL
                MOV POS,DI
                
            CONT:
                INC DI
                INC M
            JMP ANFOR
            
        ANFOR_END:  
            MOV DI,POS
            MOV BL,ARR[DI]
            XCHG BL,ARR[SI]  
            MOV ARR[DI],BL
            
            
         INC N
         INC SI
         JMP AFOR
     END_AFOR:
      RET
ASORT ENDP
           
           
DSORT PROC
    MOV SI,500
    MOV N,0
    
    DFOR:
       MOV BL,N
       CMP BL,SIZE
       JE END_DFOR
       
       MOV DI,SI
       MOV M,BL
       MOV POS,SI
       INC DI
       INC M
       MOV BL,ARR[SI]
       MOV MAX,BL
       
       DNFOR:
            MOV BL,M
            CMP BL,SIZE
            JE END_DNFOR
            
            MOV BL,ARR[DI]
            CMP BL,MAX
            JG SWAP_POSITION
            JMP CONTINUE
            
            SWAP_POSITION:    
                MOV BL,ARR[DI]
                MOV MAX,BL
                MOV POS,DI
            CONTINUE:
                INC DI
                INC M
                JMP DNFOR
        END_DNFOR:  
            MOV DI,POS
            MOV BL,MAX
            XCHG BL,ARR[SI]
            MOV ARR[DI],BL
            
            INC SI
            INC N
            JMP DFOR
            
            
    END_DFOR:

    RET
DSORT ENDP 
NEWLINE PROC
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    RET
NEWLINE ENDP    
END MAIN