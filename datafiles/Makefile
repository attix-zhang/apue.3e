ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS =	strftime strptime get_groups iter_group uname gethostname

all:	$(PROGS) getpwnam.o

%:	%.c $(LIBAPUE)
	$(CC) $(CFLAGS) $@.c -o $@.o $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
