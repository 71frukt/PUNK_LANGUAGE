PUSH 0                     
POP AX                   

PUSH 0                     
POP BX                   

PUSH AX                    
PUSH 0                   

CALL �����:   
SPU_OUT                    
HLT                        

	; ������������� ������� '�����'   
�����:

	; ������������� ���������� '�'   

POP [BX] 
PUSH BX   
PUSH 1    
ADD      
POP BX   

	; ����� ������� '���'   
PUSH AX   
	; �������� ���������� � ������� 
SPU_IN
PUSH BX   
POP AX   
CALL ���: 
POP CX  
PUSH AX  
POP BX  
POP AX  
	PUSH CX  
	; ����� ������ ������� '���'   
RET
	; ����� ������������� ������� '�����'   

	; ������������� ������� '���'   
���:

	; ������������� ���������� '�����'   

POP [BX] 
PUSH BX   
PUSH 1    
ADD      
POP BX   

	; ������ ����� if
PUSH [AX + 0]
PUSH 1

JA if_mark_0:

PUSH 1

RET
if_mark_0:
	; ����� ����� if

PUSH [AX + 0]
RET

PUSH [AX + 0]
PUSH 1

SUB 
	; ����� ������������� ������� '���'   
