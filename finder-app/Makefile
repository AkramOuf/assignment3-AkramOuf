CROSS_COMPILE ?= None

default:
ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	$(CROSS_COMPILE)gcc -o writer writer.c
else
	gcc -o writer writer.c
endif

clean:
	rm -rf *.o writer

