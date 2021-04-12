#include<bits/stdc++.h>
#include <GL/glut.h>
#include "myheader.h"
using namespace std;

void parsePolygons(string filename){
  ifstream MyReadFile(filename);
  string myText;
  pol.polygonsnumber=0;
  while (getline (MyReadFile, myText)) {
    // Ignore comments and empty lines
    if(myText[0]=='#' || myText.empty()){
      continue;
    }
    int verticesnumber;
    float red, green, blue;
    // Read no. of vertices and RGB values.
    sscanf(myText.c_str(), "%d  %f %f %f", &verticesnumber,&red,&green,&blue);
    pol.polygonsnumber++;
    pol.verticesnumbers.push_back(verticesnumber);
    pol.reds.push_back(red);
    pol.greens.push_back(green);
    pol.blues.push_back(blue);
    //int c = pol.polygonsnumber - 1;
    // cout << pol.verticesnumbers[c] << " " << pol.reds[c] << " " << pol.greens[c] << " " << pol.blues[c] << endl;
    for (int i = 0; i < verticesnumber; i++) {
      getline(MyReadFile,myText);
      int x,y;
      // Read each vertex, store all x-coordinates and y-coordinates in separate arrays.
      sscanf(myText.c_str(), "%d %d",&x,&y);
      pol.xcoordinates.push_back(x);
      pol.ycoordinates.push_back(y);
      // Find maximum y coordinate for the maximum height of the polygons window.
      if(y>maxheight){
        maxheight=y;
      }
      // cout << pol.xcoordinates[i]<< " " << pol.ycoordinates[i] << endl;
    }

  }
  MyReadFile.close();
}
