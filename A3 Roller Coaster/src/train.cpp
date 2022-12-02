// train.cpp

#include "train.h"
#include "main.h"
#include <math.h>

#define SPHERE_RADIUS 5.0
#define SPHERE_COLOUR 238/255.0, 106/255.0, 20/255.0

// Draw the train.
//
// 'flag' is toggled by pressing 'F' and can be used for debugging

 
void Train::draw( mat4 &WCStoVCS, mat4 &WCStoCCS, vec3 lightDir, bool flag )

{
#if 1
    float t = spline->paramAtArcLength( pos );

    // Draw sphere

    vec3 o, x, y, z;
    //spline->findLocalSystem( t, o, x, y, z );
    mat4 M = spline->findLocalTransform(t);
    //mat4 M   = translate( o ) * scale( SPHERE_RADIUS, SPHERE_RADIUS, SPHERE_RADIUS );
    M = M * translate(0,2,0) * scale(2.0, 2.0, 2.0);
    mat4 MV  = WCStoVCS * M;
    mat4 MVP = WCStoCCS * M;

    cylinder->drawCube( MV, MVP, lightDir, vec3(10/ 255.0, 100 / 255.0, 170 / 255.0));

#else
  
  float t = spline->paramAtArcLength( pos );
  // Draw sphere
  
  vec3 o, x, y, z;
  spline->findLocalSystem( t, o, x, y, z );
  mat4 M   = translate( o ) * scale( SPHERE_RADIUS, SPHERE_RADIUS, SPHERE_RADIUS );
  mat4 MV  = WCStoVCS * M;
  mat4 MVP = WCStoCCS * M;

  sphere->draw( MV, MVP, lightDir, vec3( SPHERE_COLOUR ) );

#endif
}


void Train::advance( float elapsedSeconds )

{
  vec3 o, x, y, z;
  float t = spline->paramAtArcLength(pos);
  spline->findLocalSystem(t, o, x, y, z);
  float slope = atan(z.z) * 180 / 3.14;
  slope = slope * 2;
  float gravity = 9.8;
  float acceleration = -1 * gravity * sin(slope * (3.14 / 180));


  acceleration = acceleration / 2;

  double accelerationPerTime = acceleration * elapsedSeconds;

  if (!isnan(accelerationPerTime)) {
	  speed += accelerationPerTime;
  }
  if (speed > 4) {
	  speed = 4;
  }
  else if (speed < 0.75) {
	  speed = 0.5;
  }
  pos += speed;
  if (pos > spline->totalArcLength()) {
	  pos = 0;
  }
  
}
