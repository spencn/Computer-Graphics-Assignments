For this assignment, you've got to read and understand much of the
code.  This README file contains only some of the information that
you'll need.

How to run it

  On Linux or MacOS, execute

    ./rt inputFilename

  The inputFilename is one of the scene descriptions in the 'worlds'
  directory, like 'worlds/testTeapot'.

  On Windows with Visual Studio, but the inputFilename in the project
  properties at as a command-line argument in the Debugging section.

Options in the window

  In the rendering window, press '?' to get a list of options in the
  console window.

  To help debugging:

    Click the mouse on a pixel to see the rays traced through that
    pixel.  You can use the mouse to rotate the scene to see the rays
    from a different viewpoint.  The rays are coloured:

      blue:   a ray that hit an object
      grey:   a ray that did not hit an object
      yellow: a shadow ray that was sent toward a point light source

  As long as you're dragging the mouse to shift the viewpoint, the scene
  will be redrawn quickly using OpenGL.  As soon as you stop dragging the
  mouse, the raytracing code is called, and eventually a raytraced image
  is shown.  You can drag the mouse again while the raytracing is being
  done; the raytracing will be restarted as soon as you stop dragging.

Input File Format

  The scene description is stored in a file.  See testBasic,
  testPhong, and testTeapot for examples and for the specific
  format. The scene description consists of these objects:

    sphere
    triangle
    wavefront

  In the scene description, you can define other things, like:

    material   A material has a name and the standard material
	       properties (Ka, Kd, Ks, n, g, Ie, alpha).  It also can
	       (optionally) have a texture map and a bump map.  Code
	       is provided to read and store these maps.  The bump
	       mapping code isn't implemented, though.

    eye        This just defines the camera parameters.

    light      This defines the position and colour of a light.  You may
	       have as many lights as you wish (two or three is
	       usually good).
