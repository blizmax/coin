#ifndef COIN_SBCYLINDERPROJECTOR_H
#define COIN_SBCYLINDERPROJECTOR_H

/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#include <Inventor/projectors/SbProjector.h>
#include <Inventor/SbCylinder.h>

class COIN_DLL_API SbCylinderProjector : public SbProjector {
  typedef SbProjector inherited;

public:
  virtual SbVec3f project(const SbVec2f & point) = 0;
  SbVec3f projectAndGetRotation(const SbVec2f & point, SbRotation & rot);
  virtual SbRotation getRotation(const SbVec3f & point1,
                                 const SbVec3f & point2) = 0;
  void setCylinder(const SbCylinder & cyl);
  const SbCylinder & getCylinder(void) const;
  void setOrientToEye(const SbBool orienttoeye);
  SbBool isOrientToEye(void) const;
  void setFront(const SbBool infront);
  SbBool isFront(void) const;
  SbBool isPointInFront(const SbVec3f & point) const;
  virtual void setWorkingSpace(const SbMatrix & space);

protected:
  SbCylinderProjector(const SbBool orienttoeye);
  SbCylinderProjector(const SbCylinder & cylinder, const SbBool orienttoeye);

  SbBool intersectCylinderFront(const SbLine & line, SbVec3f & result);

  SbBool intersectFront;
  SbCylinder cylinder;
  SbBool orientToEye;
  SbBool needSetup;
  SbVec3f lastPoint;
};

#endif // !COIN_SBCYLINDERPROJECTOR_H
