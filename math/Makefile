BASEDIR = ..
EXTRA_CFLAGS = 

LOCAL_OBJS = Math.o Plane.o Position.o Vector.o

OBJS = $(LOCAL_OBJS)
DEPS = $(LOCAL_OBJS:%.o=%.d)

.PHONY: all clean $(SUBDIR)_clean 

all: libGLOOPmath.o

libGLOOPmath.o: $(LOCAL_OBJS)
	$(AR) $@ $(OBJS)

include $(BASEDIR)/Rules.make
-include $(DEPS)
