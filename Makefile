.PHONY: clean All

All:
	@echo "----------Building project:[ CTest - Debug ]----------"
	@$(MAKE) -f  "CTest.mk"
clean:
	@echo "----------Cleaning project:[ CTest - Debug ]----------"
	@$(MAKE) -f  "CTest.mk" clean
