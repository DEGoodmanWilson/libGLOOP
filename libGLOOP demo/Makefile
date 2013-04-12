BASEDIR = ..
EXTRA_CFLAGS = 

LD_FLAGS = -lGL -lGLU -lglut

LIBS = ../math/libGLOOPmath.o ../fluid/libGLOOPfluid.o ../harness/libGLOOPharness.o
LOCAL_OBJS = main.o

SUBDIRS = ../math ../fluid ../harness

OBJS = $(LOCAL_OBJS) $(LIBS) 
DEPS = $(LOCAL_OBJS:%.o=.%.d)

.PHONY: all $(SUBDIRS)

all: demo

demo: $(LOCAL_OBJS) $(SUBDIRS)
	g++ -o demo $(OBJS) $(LD_FLAGS)


include $(BASEDIR)/Rules.make
-include $(DEPS)
