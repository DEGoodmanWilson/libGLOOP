BASEDIR = ../..
EXTRA_CFLAGS = 

LOCAL_OBJS = BucketPartition.o PotentialPoints.o SurfaceSampler.o

OBJS = $(LOCAL_OBJS)
DEPS = $(LOCAL_OBJS:%.o=%.d)

.PHONY: all clean $(SUBDIR)_clean 

all: $(LOCAL_OBJS)

include $(BASEDIR)/Rules.make
-include $(DEPS)
