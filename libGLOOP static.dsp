# Microsoft Developer Studio Project File - Name="libGLOOP static" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libGLOOP static - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "libGLOOP static.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "libGLOOP static.mak" CFG="libGLOOP static - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libGLOOP static - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libGLOOP static - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "libGLOOP static - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I ".\\" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Release\libGLOOP-static.lib"

!ELSEIF  "$(CFG)" == "libGLOOP static - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "./" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Debug\libGLOOP-static-debug.lib"

!ENDIF 

# Begin Target

# Name "libGLOOP static - Win32 Release"
# Name "libGLOOP static - Win32 Debug"
# Begin Group "Surface Representation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\fluid\SurfRep\BucketPartition.cpp
# End Source File
# Begin Source File

SOURCE=.\fluid\SurfRep\BucketPartition.h
# End Source File
# Begin Source File

SOURCE=.\fluid\SurfRep\PhysicalPoint.h
# End Source File
# Begin Source File

SOURCE=.\fluid\SurfRep\PotentialPoints.cpp
# End Source File
# Begin Source File

SOURCE=.\fluid\SurfRep\PotentialPoints.h
# End Source File
# Begin Source File

SOURCE=.\fluid\SurfRep\SurfaceSampler.cpp
# End Source File
# Begin Source File

SOURCE=.\fluid\SurfRep\SurfaceSampler.h
# End Source File
# End Group
# Begin Group "Tessellation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\fluid\Tess\ContinuousTessellator.cpp
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\ContinuousTessellator.h
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\CubePolygonizer.cpp
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\CubePolygonizer.h
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\IntVector.h
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\MarchingCube.cpp
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\MarchingCube.h
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\MarchingCubeTableNew.h
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\MarchingTetTable.h
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\SurfaceTessellator.cpp
# End Source File
# Begin Source File

SOURCE=.\fluid\Tess\SurfaceTessellator.h
# End Source File
# End Group
# Begin Group "Rendering"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\fluid\Render\ImplicitMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\fluid\Render\ImplicitMesh.h
# End Source File
# End Group
# Begin Group "Utility"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\fluid\Utility\IntHash.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\fluid\Utility\IntHash.h
# End Source File
# End Group
# End Target
# End Project
