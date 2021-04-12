#include<bits/stdc++.h>
#include <GL/glut.h>
#include "myheader.h"

using namespace std;


void myInit(void)
{
  //glClearColor(1.0,1.0,1.0,0.0);
  // // set white background color
  // glColor3f(0.0f, 0.0f, 0.0f);
  // set the drawing color
  //glPointSize(4.0);
  // a ‘dot’ is 4 by 4 pixels
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 800.0, 0.0, 600.0);
  glClear(GL_COLOR_BUFFER_BIT);
}
