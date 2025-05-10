.PHONY: all clean frontend middlend backend

all: frontend middlend backend tree

frontend:
	@echo "building frontend"
	$(MAKE) -C frontend

middlend:
	@echo "building middlend"
	$(MAKE) -C middlend

backend:
	@echo "building backend"
	$(MAKE) -C backend

tree:
	@echo "building tree"
	$(MAKE) -C tree

clean:
	@echo "cleaning frontend, middlend and backend"
	$(MAKE) -C frontend clean
	$(MAKE) -C middlend clean
	$(MAKE) -C backend clean