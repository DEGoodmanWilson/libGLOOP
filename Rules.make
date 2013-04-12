CPP = g++
CC = gcc
AR = ld -shared -o
# -Werror causes warnings to be errors
# -Woverloaded-virtual warns you if might have accidentally given your function
# a different signature, than the parent class
CFLAGS = -O9 -Wall -Woverloaded-virtual -Werror 
#CFLAGS = -g -pg -Wall -Woverloaded-virtual -Werror -D_SOLARIS

INCDIR = $(BASEDIR)

# Make rules for our project

.cpp.o: 
	$(CPP) $(CFLAGS) $(EXTRA_CFLAGS) -I$(INCDIR) -c -o $@ $<
.c.o:
	$(CPP) $(CFLAGS) $(EXTRA_CFLAGS) -I$(INCDIR) -c -o $@ $<

%.d: %.cpp
	@ set -e; $(CPP) -M $(CFLAGS) $(EXTRA_CFLAGS) -I$(INCDIR)  $< \
		| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@

%.d: %.c
	@ set -e; $(CPP) -M $(CFLAGS) $(EXTRA_CFLAGS) -I$(INCDIR) $< \
		| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@

$(SUBDIRS):
	@ $(MAKE) -C $@ 

clean:
	-rm -f core `find . \( -name '*.rej' -o -name '*~' -o \
			-name '*.[oas]' -o -size 0 -o -name '#*#' \) -print`

distclean:
	-rm -f core `find . \( -name '*.rej' -o -name '*~' -o \
			-name '*.[oasd]' -o -size 0 -o -name '#*#' \) -print`
