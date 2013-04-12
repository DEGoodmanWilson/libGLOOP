#include "harness/OpenGL.h"

#ifndef WIN32
#include <GL/glx.h>
#define wglGetProcAddress(x) glXGetProcAddressARB((GLubyte *)(x))
#endif

#include <GL/glut.h>
#include <string>
#include <iostream>

GLMULTITEXCOORD2FARBPROC OpenGL::glMultiTexCoord2fARB = NULL;
GLACTIVETEXTUREARBPROC OpenGL::glActiveTextureARB = NULL;
GLCLIENTACTIVETEXTUREARBPROC OpenGL::glClientActiveTextureARB = NULL;
int OpenGL::numMultiTextures = 1;

GLLOCKARRAYSEXTPROC OpenGL::glLockArraysEXT = NULL;
GLUNLOCKARRAYSEXTPROC OpenGL::glUnlockArraysEXT = NULL;
bool OpenGL::supportsCompiledVertexArrays = false;

GLenum OpenGL::CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE;
bool OpenGL::supportsClampToEdge = false;

GLenum OpenGL::TEXTURE_MAX_ANISOTROPY_EXT = GL_TEXTURE_MAX_ANISOTROPY_EXT;
GLenum OpenGL::MAX_TEXTURE_MAX_ANISOTROPY_EXT = GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT;
bool OpenGL::supportsAnisotropicTextures = false;

GLenum OpenGL::TEXTURE_FILTER_CONTROL_EXT = GL_TEXTURE_FILTER_CONTROL_EXT;
GLenum OpenGL::TEXTURE_LOD_BIAS_EXT = GL_TEXTURE_LOD_BIAS_EXT;
bool OpenGL::supportsTextureLodBias = false;

int OpenGL::getNumMultiTextures()
{
  return numMultiTextures;
}

bool OpenGL::getSupportsCompiledVertexArrays()
{
  return supportsCompiledVertexArrays;
}

bool OpenGL::getSupportsClampToEdge()
{
  return supportsClampToEdge;
}

bool OpenGL::getSupportsAnisotropicTextures()
{
  return supportsAnisotropicTextures;
}

bool OpenGL::getSupportsTextureLodBias()
{
  return supportsTextureLodBias;
}

void OpenGL::initExtensions()
{
  std::string extensions = std::string((char*)glGetString(GL_EXTENSIONS));

  if (extensions.find(std::string("GL_ARB_multitexture")) < extensions.max_size())
  {
    std::cout << "Found ARB_multitexture" << std::endl;
    glMultiTexCoord2fARB = (GLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
    glActiveTextureARB = (GLACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
    glClientActiveTextureARB = (GLCLIENTACTIVETEXTUREARBPROC)wglGetProcAddress("glClientActiveTextureARB");
    glGetIntegerv(GL_MAX_TEXTURE_UNITS_ARB, &numMultiTextures);
  }

  if (extensions.find(std::string("GL_EXT_compiled_vertex_array")) < extensions.max_size())
  {
    std::cout << "Found EXT_compiled_vertex_array" << std::endl;
    glLockArraysEXT = (GLLOCKARRAYSEXTPROC)wglGetProcAddress("glLockArraysEXT");
    glUnlockArraysEXT = (GLUNLOCKARRAYSEXTPROC)wglGetProcAddress("glUnlockArraysEXT");
    supportsCompiledVertexArrays = true;
  }

  if (extensions.find(std::string("GL_EXT_texture_edge_clamp")) < extensions.max_size())
  {
    std::cout << "Found EXT_texture_edge_clamp" << std::endl;
    supportsClampToEdge = true;
  }

  if (extensions.find(std::string("GL_EXT_texture_filter_anisotropic")) < extensions.max_size())
  {
    std::cout << "Found EXT_texture_filter_anisotropic" << std::endl;
    supportsAnisotropicTextures = true;
  }

  if (extensions.find(std::string("GL_EXT_texture_lod_bias")) < extensions.max_size())
  {
    std::cout << "Found EXT_texture_lod_bias" << std::endl;
    supportsTextureLodBias = true;
  }
}
