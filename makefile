.PHONY: all clean frontend middlend backend

all: frontend middlend backend tree

frontend:
	@echo "������ frontend"
	$(MAKE) -C frontend

middlend:
	@echo "������ middlend"
	$(MAKE) -C middlend

backend:
	@echo "������ backend"
	$(MAKE) -C backend

tree:
	@echo "������ tree"
	$(MAKE) -C tree

clean:
	@echo "������� ���� �����������"
	$(MAKE) -C frontend clean
	$(MAKE) -C middlend clean
	$(MAKE) -C backend clean