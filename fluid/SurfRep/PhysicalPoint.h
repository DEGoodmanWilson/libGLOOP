#ifndef PHYSICALPOINT_H
#define PHYSICALPOINT_H

//
// PhysicalPoint
//
// PhysicalPoint is the representation of a single particle moving through space, and stores all forces
// being applied upon it in the current physics frame, as well as its current velocity and position.  It
// also stores a shadow of itself, preIntegration.  This only makes sense to colliders, and is simply the
// state of the point before integration occurred (so where it was last frame.)  This is needed because
// the colliders will often have to "back up" a point if the integration step caused it to interpenetrate
// with a wall or something.
//

#include <math/Vector.h>

// This is the class itself stored in PotentialPoints.
class PhysicalPoint
{
public:
  // Basic default constructor for initialization.
  PhysicalPoint() : loc(0,0,0), strength(1.0), color(255, 255, 255) { next = 0; surfaceId = 0; }

  // Can be used to implement a velocity-based physics model involving these points.
  Vector loc;

  // this is the field strength of this point. defaults to 1
  float strength;

  // This makes them easy to string together into linked lists.
  PhysicalPoint* next;

  // This is generated every frame during tessellation and indicates which surface the point
  // is under; there's no particular order to the numbers; what they're really useful for
  // is figuring out if two points' id tags are the same, in which case they're within the
  // same surface.
  mutable int surfaceId;

  //a color for the point. not used yet.
  Vector color;
};

#endif //PHYSICALPOINT_H

