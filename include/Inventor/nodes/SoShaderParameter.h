#ifndef COIN_SOSHADERPARAMETER_H
#define COIN_SOSHADERPARAMETER_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2005 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

#include <Inventor/nodes/SoNode.h>
#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/fields/SoSFString.h>
#include <Inventor/fields/SoSFFloat.h> 
#include <Inventor/fields/SoSFInt32.h> 
#include <Inventor/fields/SoSFVec2f.h>
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/fields/SoSFVec4f.h>
#include <Inventor/fields/SoMFFloat.h>
#include <Inventor/fields/SoMFInt32.h>
#include <Inventor/fields/SoMFVec2f.h>
#include <Inventor/fields/SoMFVec3f.h>
#include <Inventor/fields/SoMFVec4f.h>
#include <Inventor/fields/SoSFMatrix.h>
#include <Inventor/fields/SoMFMatrix.h>
#include <Inventor/fields/SoSFNode.h> 
#include <Inventor/fields/SoSFEnum.h> 
#include <Inventor/fields/SoSFImage.h>

#define VEC_I32_SUPPORT 0 // FIXME: what's this? 20050120 mortene.
#if VEC_I32_SUPPORT
#include <Inventor/fields/SoSFVec2i32.h>
#include <Inventor/fields/SoSFVec3i32.h>
#include <Inventor/fields/SoSFVec4i32.h>
#include <Inventor/fields/SoMFVec2i32.h>
#include <Inventor/fields/SoMFVec3i32.h> 
#include <Inventor/fields/SoMFVec4i32.h>
#endif

class SoGLShaderParameter;
class SoGLShaderObject;

// *************************************************************************

// FIXME: split to one header file for each class? 20050120 mortene.

/* **************************************************************************
 * *** SoShaderParameter ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameter : public SoNode {
  typedef SoNode inherited;
  SO_NODE_ABSTRACT_HEADER(SoShaderParameter);

public:
  SoSFString name;
  SoSFInt32 identifier;

  SoINTERNAL public:
  static void initClass(); 

protected:
  SoShaderParameter();
  virtual ~SoShaderParameter(); 
};

/* **************************************************************************
 * *** SoUniformShaderParameter ***
 * **************************************************************************/

class COIN_DLL_API SoUniformShaderParameter : public SoShaderParameter {
  typedef SoShaderParameter inherited;
  SO_NODE_ABSTRACT_HEADER(SoUniformShaderParameter);

  SoINTERNAL public:
  static void initClass(void);
  virtual void updateParameter(SoGLShaderObject *shaderObject) = 0;
  SbBool isRegularBehavior() const { return isRegularBehaviorFlag; }

protected:
  SoUniformShaderParameter();
  virtual ~SoUniformShaderParameter();

  SbBool isRegularBehaviorFlag; 
  SoGLShaderParameter * parameter;

  void ensureParameter(SoGLShaderObject * shader);
};

/* **************************************************************************
 * *** SoShaderParameter1f ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameter1f : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameter1f);

public:
  SoSFFloat value;
  SoShaderParameter1f();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);
 
protected:
  virtual ~SoShaderParameter1f();
};

/* **************************************************************************
 * *** SoShaderParameter1i ***
 * **************************************************************************/
#if 0 // not implemented
class COIN_DLL_API SoShaderParameter1i : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameter1i);

public:
  SoSFInt32 value;
  SoShaderParameter1i();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameter1i();
};
#endif // not implemented

/* **************************************************************************
 * *** SoShaderParameter2f ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameter2f : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameter2f);

public:
  SoSFVec2f value;
  SoShaderParameter2f();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameter2f();
};

/* **************************************************************************
 * *** SoShaderParameter2i ***
 * **************************************************************************/

#if VEC_I32_SUPPORT
class COIN_DLL_API SoShaderParameter2i : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameter2i);

public:
  SoSFVec2i32 value;
  SoShaderParameter2i();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameter2i();
};
#endif

/* **************************************************************************
 * *** SoShaderParameter3f ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameter3f : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameter3f);

public:
  SoSFVec3f value;

  SoShaderParameter3f();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameter3f();
};

/* **************************************************************************
 * *** SoShaderParameter3i ***
 * **************************************************************************/

#if VEC_I32_SUPPORT
class COIN_DLL_API SoShaderParameter3i : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameter3i);

public:
  SoSFVec3i32 value;

  SoShaderParameter3i();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameter3i();
};
#endif

/* **************************************************************************
 * *** SoShaderParameter4f ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameter4f : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameter4f);

public:
  SoSFVec4f value;

  SoShaderParameter4f();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameter4f();
};

/* **************************************************************************
 * *** SoShaderParameter4i ***
 * **************************************************************************/

#if VEC_I32_SUPPORT
class COIN_DLL_API SoShaderParameter4i : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameter4i);

public:
  SoSFVec4i32 value;

  SoShaderParameter4i();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameter4i();
};
#endif

/* **************************************************************************
 * *** SoShaderParameterArray1f ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameterArray1f : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterArray1f);

public:
  SoMFFloat value;

  SoShaderParameterArray1f();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterArray1f();
};

/* **************************************************************************
 * *** SoShaderParameterArray1i ***
 * **************************************************************************/

#if 0 // not implemented
class COIN_DLL_API SoShaderParameterArray1i : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterArray1i);

public:
  SoMFInt32 value;

  SoShaderParameterArray1i();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterArray1i();
};

#endif // not implemented

/* **************************************************************************
 * *** SoShaderParameterArray2f ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameterArray2f : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterArray2f);

public:
  SoMFVec2f value;

  SoShaderParameterArray2f();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterArray2f();
};

/* **************************************************************************
 * *** SoShaderParameterArray2i ***
 * **************************************************************************/

#if VEC_I32_SUPPORT
class COIN_DLL_API SoShaderParameterArray2i : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterArray2i);

public:
  SoMFVec2i32 value;

  SoShaderParameterArray2i();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterArray2i();
};
#endif

/* **************************************************************************
 * *** SoShaderParameterArray3f ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameterArray3f : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterArray3f);

public:
  SoMFVec3f value;

  SoShaderParameterArray3f();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterArray3f();
};

/* **************************************************************************
 * *** SoShaderParameterArray3i ***
 * **************************************************************************/

#if VEC_I32_SUPPORT
class COIN_DLL_API SoShaderParameterArray3i : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterArray3i);

public:
  SoMFVec3i32 value;

  SoShaderParameterArray3i();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterArray3i();
};
#endif

/* **************************************************************************
 * *** SoShaderParameterArray4f ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameterArray4f : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterArray4f);

public:
  SoMFVec4f value;

  SoShaderParameterArray4f();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterArray4f();

};

/* **************************************************************************
 * *** SoShaderParameterArray4i ***
 * **************************************************************************/

#if VEC_I32_SUPPORT
class COIN_DLL_API SoShaderParameterArray4i : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterArray4i);

public:
  SoMFVec4i32 value;

  SoShaderParameterArray4i();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterArray4i();
};
#endif

/* **************************************************************************
 * *** SoShaderParameterMatrix ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameterMatrix : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterMatrix);

public:
  SoSFMatrix value;

  SoShaderParameterMatrix();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterMatrix();
};

/* **************************************************************************
 * *** SoShaderParameterMatrixArray ***
 * **************************************************************************/

class COIN_DLL_API SoShaderParameterMatrixArray : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderParameterMatrixArray);

public:
  SoMFMatrix value;

  SoShaderParameterMatrixArray();

  SoINTERNAL public:
  static void initClass();
  virtual void updateParameter(SoGLShaderObject *shaderObject);

protected:
  virtual ~SoShaderParameterMatrixArray();
};

/* **************************************************************************
 * *** SoShaderStateMatrixParameter ***
 * **************************************************************************/

class COIN_DLL_API SoShaderStateMatrixParameter : public SoUniformShaderParameter {
  typedef SoUniformShaderParameter inherited;
  SO_NODE_HEADER(SoShaderStateMatrixParameter);

public:

  enum MatrixType { 
    MODELVIEW,
    PROJECTION,
    TEXTURE,
    MODELVIEW_PROJECTION
  };

  enum MatrixTransform{ 
    IDENTITY,
    TRANSPOSE,
    INVERSE,
    INVERSE_TRANSPOSE
  };

  SoSFEnum matrixType;
  SoSFEnum matrixTransform;

  SoShaderStateMatrixParameter();
  virtual ~SoShaderStateMatrixParameter();

  static void initClass(void);
  virtual void updateParameter(SoGLShaderObject *shaderObject);
};

#endif /* ! COIN_SOSHADERPARAMETER_H */
