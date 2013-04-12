BASEDIR = ..
EXTRA_CFLAGS = 

RENDER_OBJS = Render/ImplicitMesh.o
SURFREP_OBJS = SurfRep/BucketPartition.o SurfRep/PotentialPoints.o \
		SurfRep/SurfaceSampler.o
TESS_OBJS = Tess/ContinuousTessellator.o Tess/CubePolygonizer.o \
		Tess/MarchingCube.o \
		Tess/RecursiveTessellator.o Tess/SurfaceTessellator.o

LOCAL_OBJS =

SUBDIRS = Render SurfRep Tess

OBJS = $(LOCAL_OBJS) $(RENDER_OBJS) $(SURFREP_OBJS) $(TESS_OBJS) 
DEPS = $(LOCAL_OBJS:%.o=%.d)

.PHONY: all $(SUBDIRS)

all: libGLOOPfluid.o

libGLOOPfluid.o: $(LOCAL_OBJS) $(SUBDIRS)
	$(AR) $@ $(OBJS)


include $(BASEDIR)/Rules.make
include $(DEPS)
