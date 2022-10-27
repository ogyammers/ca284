src = $(wildcard *.c)
out = $(src:.c=)

build: $(out)
	echo $(out)
	@true

%: %.c
	gcc -o $@ $< -lm

clean:
	rm -fv $(out)


.PHONY: clean