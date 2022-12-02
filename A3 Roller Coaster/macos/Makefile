LDFLAGS = -L. -lglfw -ldl
CXXFLAGS = -g -std=c++11 -stdlib=libc++ -Wall -Wno-write-strings -Wno-parentheses -DMACOS

vpath %.cpp ../src
vpath %.c   ../src/glad/src
vpath %.o   ../obj

OBJS = main.o scene.o ctrlPoints.o train.o terrain.o spline.o arcball.o linalg.o font.o texture.o sphere.o cylinder.o drawSegs.o gpuProgram.o axes.o lodepng.o glad.o

EXEC = roller

CXX = clang++

all:    $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) $(LDFLAGS) 

glad.o: ../src/glad/src/glad.c

clean:
	rm -f  *~ $(EXEC) $(OBJS) Makefile.bak

depend:	
	makedepend -Y ../src/*.h ../src/*.cpp 2> /dev/null
	@echo ""
	@echo "Now edit the Makefile to remove the ../src/ prefix of all of the dependences for the .o files"
	@echo ""

# DO NOT DELETE

arcball.o: ../src/headers.h ../src/glad/include/glad/glad.h
arcball.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
axes.o: ../src/linalg.h ../src/gpuProgram.h ../src/headers.h
axes.o: ../src/glad/include/glad/glad.h
axes.o: ../src/glad/include/KHR/khrplatform.h
ctrlPoints.o: ../src/headers.h ../src/glad/include/glad/glad.h
ctrlPoints.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
ctrlPoints.o: ../src/seq.h ../src/spline.h
cylinder.o: ../src/linalg.h ../src/seq.h ../src/headers.h
cylinder.o: ../src/glad/include/glad/glad.h
cylinder.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
drawSegs.o: ../src/headers.h ../src/glad/include/glad/glad.h
drawSegs.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
drawSegs.o: ../src/gpuProgram.h
gpuProgram.o: ../src/headers.h ../src/glad/include/glad/glad.h
gpuProgram.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
headers.o: ../src/glad/include/glad/glad.h
headers.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
main.o: ../src/sphere.h ../src/linalg.h ../src/seq.h ../src/headers.h
main.o: ../src/glad/include/glad/glad.h
main.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
main.o: ../src/cylinder.h ../src/axes.h ../src/drawSegs.h
scene.o: ../src/headers.h ../src/glad/include/glad/glad.h
scene.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
scene.o: ../src/gpuProgram.h ../src/arcball.h ../src/font.h
scene.o: ../src/terrain.h ../src/texture.h ../src/seq.h
scene.o: ../src/spline.h ../src/ctrlPoints.h ../src/train.h
seq.o: ../src/headers.h ../src/glad/include/glad/glad.h
seq.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
sphere.o: ../src/linalg.h ../src/seq.h ../src/headers.h
sphere.o: ../src/glad/include/glad/glad.h
sphere.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
spline.o: ../src/headers.h ../src/glad/include/glad/glad.h
spline.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
spline.o: ../src/seq.h
terrain.o: ../src/headers.h ../src/glad/include/glad/glad.h
terrain.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
terrain.o: ../src/texture.h ../src/seq.h ../src/gpuProgram.h
texture.o: ../src/headers.h ../src/glad/include/glad/glad.h
texture.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
train.o: ../src/headers.h ../src/glad/include/glad/glad.h
train.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
train.o: ../src/spline.h ../src/seq.h
arcball.o: ../src/headers.h ../src/glad/include/glad/glad.h
arcball.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
arcball.o: ../src/arcball.h
axes.o: ../src/headers.h ../src/glad/include/glad/glad.h
axes.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
axes.o: ../src/axes.h ../src/gpuProgram.h
ctrlPoints.o: ../src/ctrlPoints.h ../src/headers.h
ctrlPoints.o: ../src/glad/include/glad/glad.h
ctrlPoints.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
ctrlPoints.o: ../src/seq.h ../src/spline.h ../src/main.h
ctrlPoints.o: ../src/sphere.h ../src/gpuProgram.h ../src/cylinder.h
ctrlPoints.o: ../src/axes.h ../src/drawSegs.h
cylinder.o: ../src/cylinder.h ../src/linalg.h ../src/seq.h
cylinder.o: ../src/headers.h ../src/glad/include/glad/glad.h
cylinder.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
drawSegs.o: ../src/headers.h ../src/glad/include/glad/glad.h
drawSegs.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
drawSegs.o: ../src/drawSegs.h ../src/gpuProgram.h
font.o: ../src/headers.h ../src/glad/include/glad/glad.h
font.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
gpuProgram.o: ../src/gpuProgram.h ../src/headers.h
gpuProgram.o: ../src/glad/include/glad/glad.h
gpuProgram.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
linalg.o: ../src/linalg.h
lodepng.o: ../src/lodepng.h
main.o: ../src/headers.h ../src/glad/include/glad/glad.h
main.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
main.o: ../src/scene.h ../src/gpuProgram.h ../src/arcball.h
main.o: ../src/font.h ../src/terrain.h ../src/texture.h ../src/seq.h
main.o: ../src/spline.h ../src/ctrlPoints.h ../src/train.h
main.o: ../src/main.h ../src/sphere.h ../src/cylinder.h ../src/axes.h
main.o: ../src/drawSegs.h
scene.o: ../src/headers.h ../src/glad/include/glad/glad.h
scene.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
scene.o: ../src/scene.h ../src/gpuProgram.h ../src/arcball.h
scene.o: ../src/font.h ../src/terrain.h ../src/texture.h ../src/seq.h
scene.o: ../src/spline.h ../src/ctrlPoints.h ../src/train.h
scene.o: ../src/main.h ../src/sphere.h ../src/cylinder.h ../src/axes.h
scene.o: ../src/drawSegs.h
sphere.o: ../src/sphere.h ../src/linalg.h ../src/seq.h
sphere.o: ../src/headers.h ../src/glad/include/glad/glad.h
sphere.o: ../src/glad/include/KHR/khrplatform.h ../src/gpuProgram.h
spline.o: ../src/spline.h ../src/headers.h
spline.o: ../src/glad/include/glad/glad.h
spline.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
spline.o: ../src/seq.h ../src/main.h ../src/sphere.h
spline.o: ../src/gpuProgram.h ../src/cylinder.h ../src/axes.h
spline.o: ../src/drawSegs.h
terrain.o: ../src/terrain.h ../src/headers.h
terrain.o: ../src/glad/include/glad/glad.h
terrain.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
terrain.o: ../src/texture.h ../src/seq.h ../src/gpuProgram.h
terrain.o: ../src/main.h ../src/sphere.h ../src/cylinder.h
terrain.o: ../src/axes.h ../src/drawSegs.h
texture.o: ../src/texture.h ../src/headers.h
texture.o: ../src/glad/include/glad/glad.h
texture.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
texture.o: ../src/lodepng.h
train.o: ../src/train.h ../src/headers.h
train.o: ../src/glad/include/glad/glad.h
train.o: ../src/glad/include/KHR/khrplatform.h ../src/linalg.h
train.o: ../src/spline.h ../src/seq.h ../src/main.h ../src/sphere.h
train.o: ../src/gpuProgram.h ../src/cylinder.h ../src/axes.h
train.o: ../src/drawSegs.h
