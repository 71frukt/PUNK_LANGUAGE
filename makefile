.PHONY: all clean frontend middlend backend

all: frontend middlend backend tree

frontend:
	@echo "Сборка frontend"
	$(MAKE) -C frontend

middlend:
	@echo "Сборка middlend"
	$(MAKE) -C middlend

backend:
	@echo "Сборка backend"
	$(MAKE) -C backend

tree:
	@echo "Сборка tree"
	$(MAKE) -C tree

clean:
	@echo "Очистка всех подпроектов"
	$(MAKE) -C frontend clean
	$(MAKE) -C middlend clean
	$(MAKE) -C backend clean