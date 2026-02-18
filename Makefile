# ============================
#  Recursive Makefile
# ============================

SUBDIRS = cpp01 cpp02 cpp03 cpp04 cpp05 \
					cpp06 cpp07 cpp08 cpp09

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
