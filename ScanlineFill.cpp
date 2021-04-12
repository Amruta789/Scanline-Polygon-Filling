#include "myheader.h"
using namespace std;
void ScanlineFill(EdgeTable GlobalEdgeTable[640],float red, float green, float blue)
{
    int index, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount;
    struct EdgeTable activerow;
    activerow.countEdgeBucket=0;
    //cout << "The max height is " << maxheight << endl;
    for (int y=0; y<=maxheight; y++){
      // if GlobalEdgeTable[y] has edges greater than zero
      for(int j=0; j<GlobalEdgeTable[y].countEdgeBucket; j++){
        // Add each edge to the active edge table
        activerow.buckets.push_back(GlobalEdgeTable[y].buckets[j]);
        activerow.countEdgeBucket++;
      }
      // cout << endl << "Before remove: " << endl;
      // printActiveEdgeTable(&activerow);

      // Remove edge from active edge table, if its ymax <= y
      removeEdgeByYmax(&activerow, y);
      // cout << endl << "After remove: " << endl;
      // printActiveEdgeTable(&activerow);

      // Sort edges according to xofymin in AET
      insertionSort(&activerow);
      // cout << endl << "After sort: " << endl;
      // printActiveEdgeTable(&activerow);

      // Fill lines on scan line y by using pairs of x-coords from AET
      index = 0;
      FillFlag = 0;
      coordCount = 0;
      x1 = 0;
      x2 = 0;
      ymax1 = 0;
      ymax2 = 0;
      while (index<activerow.countEdgeBucket){
          if (coordCount%2==0){
              x1 = (int) activerow.buckets[index].xofymin;
              ymax1 = activerow.buckets[index].ymax;
              if (x1==x2){
              /* three cases can arrive-
                  1. lines are towards top of the intersection
                  2. lines are towards bottom
                  3. one line is towards top and other is towards bottom
              */
                  if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2))){
                      x2 = x1;
                      ymax2 = ymax1;
                  }else{
                      coordCount++;
                  }
              }else{
                      coordCount++;
              }
          }else{
              x2 = (int) activerow.buckets[index].xofymin;
              ymax2 = activerow.buckets[index].ymax;

              FillFlag = 0;

              // checking for intersection...
              if (x1==x2){
              /*three cases can arive-
                  1. lines are towards top of the intersection
                  2. lines are towards bottom
                  3. one line is towards top and other is towards bottom
              */
                  if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2))){
                      x1 = x2;
                      ymax1 = ymax2;
                  }else{
                      coordCount++;
                      FillFlag = 1;
                  }
              }else{
                      coordCount++;
                      FillFlag = 1;
              }
              if(FillFlag){
                  //drawing actual lines...
                  glColor3f(red,green,blue);
                  // cout << red << " " << green << endl;
                  glBegin(GL_LINES);
                  glVertex2i(x1,y);
                  glVertex2i(x2,y);
                  glEnd();
                  glFlush();
                  printf("Line drawn from %d,%d to %d,%d\n",x1,y,x2,y);
              }
          }
          index++;
      }
      // Updating xofymin by slope inverse.
      for (int i=0; i<activerow.countEdgeBucket; i++){
          // activerow.buckets[i].increment = activerow.buckets[i].denominator;
          // activerow.buckets[i].increment+=activerow.buckets[i].numerator;
          // if(activerow.buckets[i].increment > activerow.buckets[i].denominator){
          //   (activerow.buckets[i]).xofymin++;
          //   activerow.buckets[i].increment-=activerow.buckets[i].denominator;
          // }
          activerow.buckets[i].xofymin += activerow.buckets[i].minv;
      }
    }
    printf("\nScanline filling complete\n");

}
