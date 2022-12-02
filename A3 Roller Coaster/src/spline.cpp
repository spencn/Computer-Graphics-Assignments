/* spline.cpp
 */


#include "spline.h"
#include "main.h"


#define DIVS_PER_SEG 20         // number of samples of on each spline segment (for arc length parameterization)

float Spline::M[][4][4] = {

  { { 0, 0, 0, 0},              // Linear
    { 0, 0, 0, 0},
    { 0,-1, 1, 0},
    { 0, 1, 0, 0}, },

  { { -0.5,  1.5, -1.5,  0.5 }, // Catmull-Rom
    {  1.0, -2.5,  2.0, -0.5 },
    { -0.5,  0.0,  0.5,  0.0 },
    {  0.0,  1.0,  0.0,  0.0 } },

  { { -0.1667, 0.5,   -0.5,    0.1667 }, // B-spline
    {  0.5,   -1.0,    0.5,    0.0    },
    { -0.5,    0.0,    0.5,    0.0    },
    {  0.1667, 0.6667, 0.1667, 0.0    } }
  
};


const char * Spline::MName[] = {
  "linear",
  "Catmull-Rom",
  "B-spline",
  ""
};


// Evaluate the spline at parameter 't'.  Return the value, tangent
// (i.e. first derivative), or binormal, depending on the
// 'returnDerivative' parameter.
// 
// The spline is continuous, so the first data point appears again
// after the last data point.  t=0 at the first data point and t=n-1
// at the n^th data point.  For t outside this range, use 't modulo n'.
//
// Use the change-of-basis matrix in M[currSpline].

vec3 Spline::eval( float t, evalType type )
{
    // YOUR CODE HERE
    int qi;
    int qiPrev;
    int qiNext1;
    int qiNext2;
    
    ///  finding u value
    double fractpart, intpart;
    
    fractpart = modf (t, &intpart);
    
    /// stores control points
    vec3 ctrlpt[4];
    vec3 Mv[4];
    vec3 curvePoint[1];
    vec3 tangentPoint[1];
    
    /// for t outside [0,data.size()), move t into range
    if (t >= data.size()) {
        t = t - data.size();
    }
    if (t < 0) {
        t = t + data.size();
    }
    
    // calculate the point on the spline and the tangent
    for (int i = 0; i <= data.size()-1; i++) {

        /// find 4 control points:
        qi = floor(t)+i;
        qiPrev = qi-1;
        qiNext1 = qi+1;
        qiNext2 = qi+2;
        
        /// start point
        if (qi == 0) {
            qiPrev = data.size()-1;

            ctrlpt[0] = data[qiPrev];
            ctrlpt[1] = data[qi];
            ctrlpt[2] = data[qiNext1];
            ctrlpt[3] = data[qiNext2];
        } else {
            ctrlpt[0] = data[qiPrev % data.size()];
            ctrlpt[1] = data[qi % data.size()];
            ctrlpt[2] = data[qiNext1 % data.size()];
            ctrlpt[3] = data[qiNext2 % data.size()];
        }
        
        /// Compute Mv - checked
        for (int k = 0; k < 4; k++) {
            for (int m = 0; m < 3; m++) {
                Mv[k][m] = 0;
                for (int n = 0; n < 4; n++)
                Mv[k][m] += M[currSpline][k][n] * ctrlpt[n][m];
            }
        }
        
        /// u matrix
        /// value
        double u[4][1] = {pow(fractpart,3), pow(fractpart,2), pow(fractpart,1), 1};
        /// tangent
        double u_tangent[4][1] = {3 * pow(t,2), 2*t, 1};

        /// compute u MV (value)
        for (int a = 0; a < 1; a++) {
            for (int b = 0; b < 3; b++) {
                curvePoint[a][b] = 0;
                for (int c = 0; c < 4; c++)
                curvePoint[a][b] += u[a][c] * Mv[c][b];
            }
        }
        
        /// compute u MV (tangent)
        for (int a = 0; a < 1; a++) {
            for (int b = 0; b < 3; b++) {
                curvePoint[a][b] = 0;
                for (int c = 0; c < 4; c++)
                curvePoint[a][b] += u[a][c] * Mv[c][b];
            }
        }
        
        /// compute u MV (tangent)
        for (int a = 0; a < 1; a++) {
            for (int b = 0; b < 3; b++) {
                tangentPoint[a][b] = 0;
                for (int c = 0; c < 3; c++)
                tangentPoint[a][b] += u[a][c] * Mv[c][b];
            }
        }
    }

    /// If type == VALUE, return the value = T (Mv)
    if(type == VALUE) {
        return curvePoint[0];
    }
    
    /// If type == TANGENT, return the value T' (Mv)
    if (type == TANGENT) {
        return tangentPoint[0];
    }
}

// Find a local coordinate system at t.  Return the axes x,y,z.  y
// should point as much up as possible and z should point in the
// direction of increasing position on the curve.
void Spline::findLocalSystem( float t, vec3 &o, vec3 &x, vec3 &y, vec3 &z )

{

#if 1
  // YOUR CODE HERE
    
    // orgin point
    o = value(t);
    
    // z direction which is unit vector which is tangent of the curve = blue colour
    z = tangent(t).normalize();
    
    vec3 temp = z.perp1();

    y = temp.perp2();

    // cross product between z and y
    x.x = z.y * y.z - z.z * y.y;
    x.y = z.z * y.x - z.x * y.z;
    x.z = z.x * y.y - z.y * y.x;
    
#else
  
  o = vec3(0,0,0);
  x = vec3(1,0,0);
  y = vec3(0,1,0);
  z = vec3(0,0,1);

#endif
}


mat4 Spline::findLocalTransform( float t )

{
  vec3 o, x, y, z;

  findLocalSystem( t, o, x, y, z );

  mat4 M;
  M.rows[0] = vec4( x.x, y.x, z.x, o.x );
  M.rows[1] = vec4( x.y, y.y, z.y, o.y );
  M.rows[2] = vec4( x.z, y.z, z.z, o.z );
  M.rows[3] = vec4( 0, 0, 0, 1 );

  return M;
}


// Draw a point and a local coordinate system for parameter t


void Spline::drawLocalSystem( float t, mat4 &MVP )

{
  vec3 o, x, y, z;

  findLocalSystem( t, o, x, y, z );

  mat4 M;
  M.rows[0] = vec4( x.x, y.x, z.x, o.x );
  M.rows[1] = vec4( x.y, y.y, z.y, o.y );
  M.rows[2] = vec4( x.z, y.z, z.z, o.z );
  M.rows[3] = vec4( 0, 0, 0, 1 );

  M = MVP * M * scale(6,6,6);
  axes->draw(M);
}


// Draw the spline with even parameter spacing


void Spline::draw( mat4 &MV, mat4 &MVP, vec3 lightDir, bool drawIntervals )

{
  // Draw the spline
  
  vec3 *points = new vec3[ data.size()*DIVS_PER_SEG + 1 ];
  vec3 *colours = new vec3[ data.size()*DIVS_PER_SEG + 1 ];

  int i = 0;
  for (float t=0; t<data.size(); t+=1/(float)DIVS_PER_SEG) {
    points[i] = value( t );
    colours[i] = SPLINE_COLOUR;
    i++;
  }

  segs->drawSegs( GL_LINE_LOOP, points, colours, i, MV, MVP, lightDir );

  // Draw points evenly spaced in the parameter

  if (drawIntervals)
    for (float t=0; t<data.size(); t+=1/(float)DIVS_PER_SEG)
      drawLocalSystem( t, MVP );

  delete[] points;
  delete[] colours;
}


// Draw the spline with even arc-length spacing


void Spline::drawWithArcLength( mat4 &MV, mat4 &MVP, vec3 lightDir, bool drawIntervals )

{
  // Draw the spline
  
  vec3 *points = new vec3[ data.size()*DIVS_PER_SEG + 1 ];
  vec3 *colours =  new vec3[ data.size()*DIVS_PER_SEG + 1 ];

  int i = 0;
  for (float t=0; t<data.size(); t+=1/(float)DIVS_PER_SEG) {
    points[i] = value( t );
    colours[i] = SPLINE_COLOUR;
    i++;
  }

  segs->drawSegs( GL_LINE_LOOP, points, colours, i, MV, MVP, lightDir );

  // Draw points evenly spaced in arc length

  if (drawIntervals) {
    
    float totalLength = totalArcLength();

    for (float s=0; s<totalLength; s+=totalLength/(float)(data.size()*DIVS_PER_SEG)) {
      float t = paramAtArcLength( s );
      drawLocalSystem( t, MVP );
    }
  }

  delete[] points;
  delete[] colours;
}


// Fill in an arcLength array such that arcLength[i] is the estimated
// arc length up to the i^th sample (using DIVS_PER_SEG samples per
// spline segment).


void Spline::computeArcLengthParameterization()

{
  if (data.size() == 0)
    return;

  if (arcLength != NULL)
    delete [] arcLength;

  arcLength = new float[ data.size() * DIVS_PER_SEG + 1 ];

  // first sample at length 0

  arcLength[0] = 0;
  vec3 prev = value(0);

  maxHeight = prev.z;

  // Compute intermediate lengths

  int k = 1;
  
  for (int i=0; i<data.size(); i++)
    for (int j=(i>0?0:1); j<DIVS_PER_SEG; j++) {

      vec3 next = value( i + j/(float)DIVS_PER_SEG );

      arcLength[k] = arcLength[k-1] + (next-prev).length();
      prev = next;
      k++;

      if (next.z > maxHeight)
        maxHeight = next.z;
    }

  // last sample at full length

  vec3 next = value( data.size() );
  arcLength[k] = arcLength[k-1] + (next-prev).length();

  if (next.z > maxHeight)
    maxHeight = next.z;
  
  mustRecomputeArcLength = false;
}


// Find the spline parameter at a particular arc length, s.


float Spline::paramAtArcLength( float s )

{
  if (mustRecomputeArcLength)
    computeArcLengthParameterization();

  // Do binary search on arc lengths to find l such that 
  //
  //        arcLength[l] <= s < arcLength[l+1].

  if (s < 0)
    s += arcLength[ data.size() * DIVS_PER_SEG ];

  int l = 0;
  int r = data.size()*DIVS_PER_SEG;

  while (r-l > 1) {
    int m = (l+r)/2;
    if (arcLength[m] <= s)
      l = m;
    else
      r = m;
  }

  if (arcLength[l] > s || arcLength[l+1] <= s)
    return (l + 0.5) / (float) DIVS_PER_SEG;
  
  // Do linear interpolation in arcLength[l] ... arcLength[l+1] to
  // find position of s.

  float p = (s - arcLength[l]) / (arcLength[l+1] - arcLength[l]);

  // Return the curve parameter at s

  return (l+p) / (float) DIVS_PER_SEG;
}



float Spline::totalArcLength()

{
  if (data.size() == 0)
    return 0;

  if (mustRecomputeArcLength)
    computeArcLengthParameterization();

  return arcLength[ data.size() * DIVS_PER_SEG ];
}
