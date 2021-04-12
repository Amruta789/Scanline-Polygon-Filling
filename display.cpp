#include<bits/stdc++.h>
#include <GL/glut.h>
#include "myheader.h"
using namespace std;

void display(){
  // For each polygon in pol
  for(int i=0, j=0; i < pol.polygonsnumber; i++){
      // Create a global edge table and initialize count of edges for each ymin index as zero.
      struct EdgeTable GlobalEdgeTable[640];
      for(int l=0; l<maxheight; l++){
        GlobalEdgeTable[l].countEdgeBucket=0;
      }
      glColor3f(pol.reds[i], pol.greens[i], pol.blues[i]);
      // Draw the polygon with the corresponding color.
      glBegin(GL_LINE_LOOP);
      int jstart=j;
      int firstx=pol.xcoordinates[j];
      int firsty=pol.ycoordinates[j];
      // Read each vertex and store edge with next vertex
      while(j+1-jstart < pol.verticesnumbers[i]){
        glVertex2i(pol.xcoordinates[j], pol.ycoordinates[j]);
        //cout << pol.xcoordinates[j] << pol.ycoordinates[j] << endl;

        // Store edge in Global Edge Table
        storeEdge(GlobalEdgeTable, pol.xcoordinates[j],pol.ycoordinates[j],pol.xcoordinates[j+1], pol.ycoordinates[j+1]);
        //cout << "j=" << j << "k=" << k << endl;
        j++;
      }
      glVertex2i(pol.xcoordinates[j], pol.ycoordinates[j]);
      // Store edge of last vertex with first vertex
      storeEdge(GlobalEdgeTable, pol.xcoordinates[j],pol.ycoordinates[j],firstx, firsty);
      j++;
      glEnd();
      // cout << pol.reds[i] << " " << pol.greens[i] << endl;
      //printAllEdges(GlobalEdgeTable);

      // Fill the polygon with edges from Global Edge Table and colors as input.
      ScanlineFill(GlobalEdgeTable, pol.reds[i], pol.greens[i], pol.blues[i]);

  }
  // cout << " Total No. of vertices: " << pol.xcoordinates.size() << endl;
  glFlush();
}
