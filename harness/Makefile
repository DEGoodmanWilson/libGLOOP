BASEDIR = ..
EXTRA_CFLAGS = 

LOCAL_OBJS = OpenGL.o PlatformSpecific.o TextureManager.o

OBJS = $(LOCAL_OBJS)
DEPS = $(LOCAL_OBJS:%.o=%.d)

.PHONY: all clean $(SUBDIR)_clean 

all: libGLOOPharness.o

libGLOOPharness.o: $(LOCAL_OBJS)
	$(AR) $@ $(OBJS)

include $(BASEDIR)/Rules.make
-include $(DEPS)
