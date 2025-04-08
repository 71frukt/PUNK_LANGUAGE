.PHONY: all clean frontend middlend backend

all: frontend middlend backend

frontend:
	@echo "Запуск frontend"
	$(MAKE) -C frontend

middlend:
	@echo "Запуск middlend"
	$(MAKE) -C middlend

backend:
	@echo "Запуск backend"
	$(MAKE) -C backend

clean:
	@echo "Очистка всех подпроектов"
	$(MAKE) -C frontend clean
	$(MAKE) -C middlend clean
	$(MAKE) -C backend clean