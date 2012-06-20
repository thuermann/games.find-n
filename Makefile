#
# $Id: Makefile,v 1.1 2012/06/20 10:25:16 urs Exp $
#

RM      = rm -f
CFLAGS  = -Os
LDFLAGS = -s

programs = find-n

.PHONY: all
all: $(programs)

.PHONY: clean
clean:
	$(RM) $(programs) *.o core
