# If you want text output in the window, you need to install the open
# source freetype package.  On Linux, do "sudo apt-get install libfreetype6-dev".

# If you don't have freetype, use this:

LDFLAGS  = -L. -lglfw -lGL -ldl
CXXFLAGS = -g -DLINUX -Wall -Wno-deprecated -Wno-sign-compare -std=c++11

# If you have installed the freetype package, use this:

#LDFLAGS  = -L. -lglfw -lGL -ldl -lfreetype
#CXXFLAGS = -g -DLINUX -Wall -Wno-deprecated -Wno-sign-compare -std=c++11 -DHAVE_FREETYPE -I/usr/include/freetype2

vpath %.cpp ../src
vpath %.c   ../src/glad/src

OBJS =	bvh.o linalg.o arcball.o font.o sphere.o triangle.o light.o eye.o object.o gpuProgram.o axes.o arrow.o bbox.o drawSegs.o glad.o \
	material.o texture.o vertex.o wavefrontobj.o wavefront.o rtWindow.o main.o scene.o pixelZoom.o

EXEC = rt

all:	$(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) $(LDFLAGS) 

#glad.o:	glad.c
#	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *~ $(EXEC) $(OBJS) Makefile.bak

depend:	
	makedepend -Y ../src/*.h ../src/*.cpp 2> /dev/null
	@echo ""
	@echo "Now edit the Makefile to remove the ../src/ prefix of all of the dependences for the .o files"
	@echo ""

# DO NOT DELETE

arcball.o: ../src/headers.h ../src/glad/include/glad/glad.h
arcball.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
arrow.o: ../src/object.h ../src/linalg.h ../src/material.h
arrow.o: ../src/texture.h ../src/headers.h
arrow.o: ../src/glad/include/glad/glad.h
arrow.o: ../src/glad/include/KHR/khrplatform.h ../src/seq.h
arrow.o: ../src/gpuProgram.h
axes.o: ../src/linalg.h ../src/gpuProgram.h ../src/headers.h
axes.o: ../src/glad/include/glad/glad.h
axes.o: ../src/glad/include/KHR/khrplatform.h ../src/seq.h
bbox.o: ../src/linalg.h
bvh.o: ../src/linalg.h ../src/seq.h ../src/material.h ../src/texture.h
bvh.o: ../src/headers.h ../src/glad/include/glad/glad.h
bvh.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
bvh.o: ../src/bbox.h ../src/main.h ../src/scene.h ../src/object.h
bvh.o: ../src/light.h ../src/sphere.h ../src/eye.h ../src/axes.h
bvh.o: ../src/drawSegs.h ../src/arrow.h ../src/rtWindow.h
bvh.o: ../src/arcball.h ../src/pixelZoom.h ../src/wavefront.h
bvh.o: ../src/shadeMode.h
drawSegs.o: ../src/headers.h ../src/glad/include/glad/glad.h
drawSegs.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
drawSegs.o: ../src/gpuProgram.h ../src/seq.h
eye.o: ../src/linalg.h
gpuProgram.o: ../src/headers.h ../src/glad/include/glad/glad.h
gpuProgram.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
gpuProgram.o: ../src/seq.h
headers.o: ../src/glad/include/glad/glad.h
headers.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
light.o: ../src/linalg.h ../src/sphere.h ../src/seq.h
light.o: ../src/gpuProgram.h ../src/headers.h
light.o: ../src/glad/include/glad/glad.h
light.o: ../src/glad/include/KHR/khrplatform.h ../src/object.h
light.o: ../src/material.h ../src/texture.h
main.o: ../src/seq.h ../src/scene.h ../src/linalg.h ../src/object.h
main.o: ../src/material.h ../src/texture.h ../src/headers.h
main.o: ../src/glad/include/glad/glad.h
main.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
main.o: ../src/light.h ../src/sphere.h ../src/eye.h ../src/axes.h
main.o: ../src/drawSegs.h ../src/arrow.h ../src/rtWindow.h
main.o: ../src/main.h ../src/pixelZoom.h ../src/arcball.h
material.o: ../src/linalg.h ../src/texture.h ../src/headers.h
material.o: ../src/glad/include/glad/glad.h
material.o: ../src/glad/include/KHR/khrplatform.h ../src/seq.h
material.o: ../src/gpuProgram.h
object.o: ../src/linalg.h ../src/material.h ../src/texture.h
object.o: ../src/headers.h ../src/glad/include/glad/glad.h
object.o: ../src/glad/include/KHR/khrplatform.h ../src/seq.h
object.o: ../src/gpuProgram.h
pixelZoom.o: ../src/gpuProgram.h ../src/headers.h
pixelZoom.o: ../src/glad/include/glad/glad.h
pixelZoom.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
pixelZoom.o: ../src/seq.h
rtWindow.o: ../src/main.h ../src/seq.h ../src/scene.h ../src/linalg.h
rtWindow.o: ../src/object.h ../src/material.h ../src/texture.h
rtWindow.o: ../src/headers.h ../src/glad/include/glad/glad.h
rtWindow.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
rtWindow.o: ../src/light.h ../src/sphere.h ../src/eye.h ../src/axes.h
rtWindow.o: ../src/drawSegs.h ../src/arrow.h ../src/rtWindow.h
rtWindow.o: ../src/arcball.h ../src/pixelZoom.h
scene.o: ../src/seq.h ../src/linalg.h ../src/object.h
scene.o: ../src/material.h ../src/texture.h ../src/headers.h
scene.o: ../src/glad/include/glad/glad.h
scene.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
scene.o: ../src/light.h ../src/sphere.h ../src/eye.h ../src/axes.h
scene.o: ../src/drawSegs.h ../src/arrow.h
sphere.o: ../src/linalg.h ../src/seq.h ../src/gpuProgram.h
sphere.o: ../src/headers.h ../src/glad/include/glad/glad.h
sphere.o: ../src/glad/include/KHR/khrplatform.h ../src/object.h
sphere.o: ../src/material.h ../src/texture.h
texture.o: ../src/headers.h ../src/glad/include/glad/glad.h
texture.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
texture.o: ../src/seq.h
triangle.o: ../src/object.h ../src/linalg.h ../src/material.h
triangle.o: ../src/texture.h ../src/headers.h
triangle.o: ../src/glad/include/glad/glad.h
triangle.o: ../src/glad/include/KHR/khrplatform.h ../src/seq.h
triangle.o: ../src/gpuProgram.h ../src/vertex.h
vertex.o: ../src/linalg.h
wavefront.o: ../src/headers.h ../src/glad/include/glad/glad.h
wavefront.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
wavefront.o: ../src/seq.h ../src/shadeMode.h ../src/gpuProgram.h
wavefrontobj.o: ../src/object.h ../src/linalg.h ../src/material.h
wavefrontobj.o: ../src/texture.h ../src/headers.h
wavefrontobj.o: ../src/glad/include/glad/glad.h
wavefrontobj.o: ../src/glad/include/KHR/khrplatform.h ../src/seq.h
wavefrontobj.o: ../src/gpuProgram.h ../src/wavefront.h
wavefrontobj.o: ../src/shadeMode.h ../src/bvh.h ../src/bbox.h
wavefrontobj.o: ../src/main.h ../src/scene.h ../src/light.h
wavefrontobj.o: ../src/sphere.h ../src/eye.h ../src/axes.h
wavefrontobj.o: ../src/drawSegs.h ../src/arrow.h ../src/rtWindow.h
wavefrontobj.o: ../src/arcball.h ../src/pixelZoom.h
arcball.o: ../src/headers.h ../src/glad/include/glad/glad.h
arcball.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
arcball.o: ../src/arcball.h
arrow.o: ../src/headers.h ../src/glad/include/glad/glad.h
arrow.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
arrow.o: ../src/arrow.h ../src/object.h ../src/material.h
arrow.o: ../src/texture.h ../src/seq.h ../src/gpuProgram.h
axes.o: ../src/headers.h ../src/glad/include/glad/glad.h
axes.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
axes.o: ../src/axes.h ../src/gpuProgram.h ../src/seq.h
bbox.o: ../src/headers.h ../src/glad/include/glad/glad.h
bbox.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
bbox.o: ../src/bbox.h ../src/drawSegs.h ../src/gpuProgram.h
bbox.o: ../src/seq.h ../src/main.h ../src/scene.h ../src/object.h
bbox.o: ../src/material.h ../src/texture.h ../src/light.h
bbox.o: ../src/sphere.h ../src/eye.h ../src/axes.h ../src/arrow.h
bbox.o: ../src/rtWindow.h ../src/arcball.h ../src/pixelZoom.h
bvh.o: ../src/bvh.h ../src/linalg.h ../src/seq.h ../src/material.h
bvh.o: ../src/texture.h ../src/headers.h
bvh.o: ../src/glad/include/glad/glad.h
bvh.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
bvh.o: ../src/bbox.h ../src/main.h ../src/scene.h ../src/object.h
bvh.o: ../src/light.h ../src/sphere.h ../src/eye.h ../src/axes.h
bvh.o: ../src/drawSegs.h ../src/arrow.h ../src/rtWindow.h
bvh.o: ../src/arcball.h ../src/pixelZoom.h ../src/wavefront.h
bvh.o: ../src/shadeMode.h ../src/triangle.h ../src/vertex.h
drawSegs.o: ../src/headers.h ../src/glad/include/glad/glad.h
drawSegs.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
drawSegs.o: ../src/drawSegs.h ../src/gpuProgram.h ../src/seq.h
eye.o: ../src/headers.h ../src/glad/include/glad/glad.h
eye.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
eye.o: ../src/eye.h ../src/main.h ../src/seq.h ../src/scene.h
eye.o: ../src/object.h ../src/material.h ../src/texture.h
eye.o: ../src/gpuProgram.h ../src/light.h ../src/sphere.h
eye.o: ../src/axes.h ../src/drawSegs.h ../src/arrow.h
eye.o: ../src/rtWindow.h ../src/arcball.h ../src/pixelZoom.h
font.o: ../src/headers.h ../src/glad/include/glad/glad.h
font.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
gpuProgram.o: ../src/gpuProgram.h ../src/headers.h
gpuProgram.o: ../src/glad/include/glad/glad.h
gpuProgram.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
gpuProgram.o: ../src/seq.h
light.o: ../src/headers.h ../src/glad/include/glad/glad.h
light.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
light.o: ../src/light.h ../src/sphere.h ../src/seq.h
light.o: ../src/gpuProgram.h ../src/object.h ../src/material.h
light.o: ../src/texture.h ../src/main.h ../src/scene.h ../src/eye.h
light.o: ../src/axes.h ../src/drawSegs.h ../src/arrow.h
light.o: ../src/rtWindow.h ../src/arcball.h ../src/pixelZoom.h
linalg.o: ../src/linalg.h
main.o: ../src/headers.h ../src/glad/include/glad/glad.h
main.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
main.o: ../src/rtWindow.h ../src/main.h ../src/seq.h ../src/scene.h
main.o: ../src/object.h ../src/material.h ../src/texture.h
main.o: ../src/gpuProgram.h ../src/light.h ../src/sphere.h
main.o: ../src/eye.h ../src/axes.h ../src/drawSegs.h ../src/arrow.h
main.o: ../src/pixelZoom.h ../src/arcball.h ../src/font.h
material.o: ../src/headers.h ../src/glad/include/glad/glad.h
material.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
material.o: ../src/material.h ../src/texture.h ../src/seq.h
material.o: ../src/gpuProgram.h ../src/main.h ../src/scene.h
material.o: ../src/object.h ../src/light.h ../src/sphere.h
material.o: ../src/eye.h ../src/axes.h ../src/drawSegs.h
material.o: ../src/arrow.h ../src/rtWindow.h ../src/arcball.h
material.o: ../src/pixelZoom.h
object.o: ../src/headers.h ../src/glad/include/glad/glad.h
object.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
object.o: ../src/object.h ../src/material.h ../src/texture.h
object.o: ../src/seq.h ../src/gpuProgram.h ../src/main.h
object.o: ../src/scene.h ../src/light.h ../src/sphere.h ../src/eye.h
object.o: ../src/axes.h ../src/drawSegs.h ../src/arrow.h
object.o: ../src/rtWindow.h ../src/arcball.h ../src/pixelZoom.h
pixelZoom.o: ../src/pixelZoom.h ../src/gpuProgram.h ../src/headers.h
pixelZoom.o: ../src/glad/include/glad/glad.h
pixelZoom.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
pixelZoom.o: ../src/seq.h
rtWindow.o: ../src/rtWindow.h ../src/main.h ../src/seq.h
rtWindow.o: ../src/scene.h ../src/linalg.h ../src/object.h
rtWindow.o: ../src/material.h ../src/texture.h ../src/headers.h
rtWindow.o: ../src/glad/include/glad/glad.h
rtWindow.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
rtWindow.o: ../src/light.h ../src/sphere.h ../src/eye.h ../src/axes.h
rtWindow.o: ../src/drawSegs.h ../src/arrow.h ../src/pixelZoom.h
rtWindow.o: ../src/arcball.h
scene.o: ../src/headers.h ../src/glad/include/glad/glad.h
scene.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
scene.o: ../src/scene.h ../src/seq.h ../src/object.h ../src/material.h
scene.o: ../src/texture.h ../src/gpuProgram.h ../src/light.h
scene.o: ../src/sphere.h ../src/eye.h ../src/axes.h ../src/drawSegs.h
scene.o: ../src/arrow.h ../src/rtWindow.h ../src/main.h
scene.o: ../src/pixelZoom.h ../src/arcball.h ../src/triangle.h
scene.o: ../src/vertex.h ../src/wavefrontobj.h ../src/wavefront.h
scene.o: ../src/shadeMode.h ../src/bvh.h ../src/bbox.h ../src/font.h
sphere.o: ../src/sphere.h ../src/linalg.h ../src/seq.h
sphere.o: ../src/gpuProgram.h ../src/headers.h
sphere.o: ../src/glad/include/glad/glad.h
sphere.o: ../src/glad/include/KHR/khrplatform.h ../src/object.h
sphere.o: ../src/material.h ../src/texture.h ../src/main.h
sphere.o: ../src/scene.h ../src/light.h ../src/eye.h ../src/axes.h
sphere.o: ../src/drawSegs.h ../src/arrow.h ../src/rtWindow.h
sphere.o: ../src/arcball.h ../src/pixelZoom.h
texture.o: ../src/headers.h ../src/glad/include/glad/glad.h
texture.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
texture.o: ../src/texture.h ../src/seq.h
triangle.o: ../src/headers.h ../src/glad/include/glad/glad.h
triangle.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
triangle.o: ../src/triangle.h ../src/object.h ../src/material.h
triangle.o: ../src/texture.h ../src/seq.h ../src/gpuProgram.h
triangle.o: ../src/vertex.h ../src/main.h ../src/scene.h
triangle.o: ../src/light.h ../src/sphere.h ../src/eye.h ../src/axes.h
triangle.o: ../src/drawSegs.h ../src/arrow.h ../src/rtWindow.h
triangle.o: ../src/arcball.h ../src/pixelZoom.h
vertex.o: ../src/headers.h ../src/glad/include/glad/glad.h
vertex.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
vertex.o: ../src/vertex.h ../src/main.h ../src/seq.h ../src/scene.h
vertex.o: ../src/object.h ../src/material.h ../src/texture.h
vertex.o: ../src/gpuProgram.h ../src/light.h ../src/sphere.h
vertex.o: ../src/eye.h ../src/axes.h ../src/drawSegs.h ../src/arrow.h
vertex.o: ../src/rtWindow.h ../src/arcball.h ../src/pixelZoom.h
wavefront.o: ../src/headers.h ../src/glad/include/glad/glad.h
wavefront.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
wavefront.o: ../src/gpuProgram.h ../src/seq.h ../src/wavefront.h
wavefront.o: ../src/shadeMode.h
wavefrontobj.o: ../src/headers.h ../src/glad/include/glad/glad.h
wavefrontobj.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
wavefrontobj.o: ../src/wavefrontobj.h ../src/object.h
wavefrontobj.o: ../src/material.h ../src/texture.h ../src/seq.h
wavefrontobj.o: ../src/gpuProgram.h ../src/wavefront.h
wavefrontobj.o: ../src/shadeMode.h ../src/bvh.h ../src/bbox.h
wavefrontobj.o: ../src/main.h ../src/scene.h ../src/light.h
wavefrontobj.o: ../src/sphere.h ../src/eye.h ../src/axes.h
wavefrontobj.o: ../src/drawSegs.h ../src/arrow.h ../src/rtWindow.h
wavefrontobj.o: ../src/arcball.h ../src/pixelZoom.h
