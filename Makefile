# Top level makefile

default: LISPB

.DEFAULT:
	cd src && $(MAKE) $@
