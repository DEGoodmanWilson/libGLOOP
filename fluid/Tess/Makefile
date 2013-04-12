BASEDIR = ../..
EXTRA_CFLAGS = 

LOCAL_OBJS = ContinuousTessellator.o CubePolygonizer.o MarchingCube.o RecursiveTessellator.o SurfaceTessellator.o

OBJS = $(LOCAL_OBJS)
DEPS = $(LOCAL_OBJS:%.o=%.d)

.PHONY: all clean $(SUBDIR)_clean 

all: $(LOCAL_OBJS)

include $(BASEDIR)/Rules.make
-include $(DEPS)
