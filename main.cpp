#include<bits/stdc++.h>
#include <GL/glut.h>
#include "myheader.h"
using namespace std;

struct Polygons pol;
int maxheight=0;

int main(int argc, char** argv)
{
    if(argc!=2){
      printf("Give only 1 file for input\n");
      return 0;
    }
    string filename=argv[1];
    cout << filename << endl;
    // read all vertices from the filename
    parsePolygons(filename);

    int mode=GLUT_RGB|GLUT_SINGLE;
    glutInit(&argc, argv);
    glutInitDisplayMode(mode);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Scanline polygon filling");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
