org 100h
    MOV DX, OFFSET msg ; load offset of msg into dx
    
    MOV AH, 9H         ; print function is 9
    
    INT 21H            ; do it! 
    
ret                    ; return to operating system


msg DB "Hello World!$"
