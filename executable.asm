PUSH 0                     
POP AX                   

PUSH 0                     
POP BX                   

PUSH AX                    
PUSH 0                   

CALL main:   
SPU_OUT                    
HLT                        

	; ������������� ������� 'main'   
main:

	; ������������� ���������� 'arg'   

POP [BX] 
PUSH BX   
PUSH 1    
ADD      
POP BX   

	; ����� ������� 'fact'   
PUSH AX   
	; �������� ���������� � ������� 
PUSH 6

PUSH 2

MUL 
PUSH BX   
POP AX   
CALL fact: 
POP CX  
PUSH AX  
POP BX  
POP AX  
	PUSH CX  
	; ����� ������ ������� 'fact'   
RET
	; ����� ������������� ������� 'main'   

	; ������������� ������� 'fact'   
fact:

	; ������������� ���������� 'n'   

POP [BX] 
PUSH BX   
PUSH 1    
ADD      
POP BX   

	; ������ ����� if
PUSH [AX + 0]
PUSH 1

JNE if_mark_0:

PUSH 1

RET
if_mark_0:
	; ����� ����� if

	; ������������� ���������� 'next'   
PUSH 0


POP [BX] 
PUSH BX   
PUSH 1    
ADD      
POP BX   

	; ������������ �������� ���������� 'next'
	; ����� ������� 'fact'   
PUSH AX   
	; �������� ���������� � ������� 
PUSH [AX + 0]
PUSH 1

SUB 
PUSH BX   
POP AX   
CALL fact: 
POP CX  
PUSH AX  
POP BX  
POP AX  
	PUSH CX  
	; ����� ������ ������� 'fact'   
POP [AX + 1]

PUSH [AX + 1]
PUSH [AX + 0]
MUL 
RET
	; ����� ������������� ������� 'fact'   
