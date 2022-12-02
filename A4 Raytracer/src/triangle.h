/* triangle.h
 */


#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "object.h"
#include "vertex.h"


class Triangle : public Object {

  
  vec3 faceNormal;		// triangle normal
  float  barycentricFactor;     // factor used in computing local coords
  float  dist;			// distance origin-to-plane of triangle
  GLuint VAO;

 public:
  Vertex verts[3];		// three vertices of the triangle
  Triangle() {
    VAO = 0;
  }

  bool rayInt( vec3 rayStart, vec3 rayDir, int objPartIndex, float maxParam,
	       vec3 &intPoint, vec3 &intNorm, vec3 &intTexCoords, float &intParam, Material *&mat, int &intPartIndex );

  void input( istream &stream );
  void output( ostream &stream ) const;
  void renderGL( GPUProgram *prog, mat4 &WCS_to_VCS, mat4 &VCS_to_CCS );
  vec3 textureColour( vec3 &p, int objPartIndex, float &alpha, vec3 &texCoords );
};

#endif
