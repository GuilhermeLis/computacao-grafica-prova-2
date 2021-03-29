## Getting Started

Requirements for each activity:

- Region Filling: to create a new fill pattern, change colors and fill patterns only from the inner area of the selected square, correct the rectangle area when the user resizes the window through the glutReshapeFunc function.

- Geometric Transformations: to create an object whose parts can be controlled by the keyboard

- Animations: to use the object created in the geometric transformation and control it by the animation function.

- Lighting: to create a scene that contains lighting.

### Prerequisites

I used Visual Code to develop my programs, but you can use the IDE or Text Editor of your choice.

To use the OpenGL library, you must run the following command lines:

- sudo apt-get install freeglut3 freeglut3-dev

- sudo ln -s /usr/lib/x86_64-linux-gnu/libglut.a /usr/lib/libglut.a

- sudo ln -s /usr/lib/x86_64-linux-gnu/libglut.so /usr/lib/libglut.so

- sudo ln -s /usr/lib/x86_64-linux-gnu/libGL.so /usr/lib/libGL.so

- sudo ln -s /usr/lib/x86_64-linux-gnu/libglapi.so /usr/lib/libglapi.so

- sudo ln -s /usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/libGLU.so

- sudo ln -s /usr/lib/x86_64-linux-gnu/libGLU.a /usr/lib/libGLU.a

To run your program, you must write the following command lines:

g++ NameOfYourProgram.cpp -o build/NameOfYourProgram -lGL -lGLU -lglut && ./build/NameOfYourProgram

P.S.: Don't forget to write the libs in that particular order.
