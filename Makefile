BASEDIR = $(PWD)

SUBDIRS = fluid harness math

.PHONY : all subdirs $(SUBDIRS) clean
all: subdirs

subdirs: $(SUBDIRS)


include $(BASEDIR)/Rules.make
