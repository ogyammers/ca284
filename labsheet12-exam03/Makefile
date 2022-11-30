.POSIX:

AUTHOR="Jamie Gorman"
PROGRAM=`ls -ltr *.c | tail -1 | awk '{print $$9}'`

src = $(wildcard *.c)
out = $(src:.c=)

build: $(out)
	@true

%: %.c
	gcc -o $@ $< -lm

clean:
	rm -fv $(out)

tmp:
	@echo "/*"
	@echo "Program: "$(PROGRAM)
	@echo "Author:"$(AUTHOR)
	@echo "Date:"
	@echo "Input:"
	@echo "Output:"
	@echo "*/"
	@echo 
	@echo "/*Includes */"
	@echo "#include <stdio.h>"
	@echo "#include <string.h>"
	@echo "#include <stdlib.h>"
	@echo 
	@echo "/*Type definitions*/"
	@echo 
	@echo "/*Structure definitions*/"
	@echo 
	@echo "/*Function prototypes*/"
	@echo 
	@echo "/*Main driver function*/"
	@echo "int main(int argc, char *argv[])"
	@echo "{"
	@echo "	return 0;"
	@echo "}"

.PHONY: clean template
