# ============================
#  Recursive Makefile
# ============================

SUBDIRS = ex00 ex01 ex02 ex03 ex04 ex05 ex06

all:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir re; \
	done
