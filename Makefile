DIRS = $(wildcard */.)

.PHONY: build clean

build clean:
	for dir in $(DIRS); do \
		$(MAKE) -C $$dir -f Makefile $@; \
	done