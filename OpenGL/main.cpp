#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <GL/glut.h>


int main() {

  glutInit(&argc, argv[]);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

  glutInitWindowSize(800,600);
  glutCreateWindow("OpenGL lesson 1");

  glutReshapeFunc(reshape);
  glutDisplayFunc(display);

  glutMainLoop();

  return 0;

}
