#include "myheader.h"
using namespace std;
// Sort edges according to xofymin in the bucketss
void insertionSort(EdgeTable *activerow){
    int i,j;
    struct Edge temp;

    for (i = 1; i < activerow->countEdgeBucket; i++)
    {
        temp.ymin = activerow->buckets[i].ymin;
        temp.ymax = activerow->buckets[i].ymax;
        temp.xofymin = activerow->buckets[i].xofymin;
        temp.xofymax = activerow->buckets[i].xofymax;
        // temp.numerator = activerow->buckets[i].numerator;
        // temp.denominator = activerow->buckets[i].denominator;
        // temp.increment = activerow->buckets[i].increment;
        temp.minv = activerow->buckets[i].minv;
        j = i - 1;

        while ((temp.xofymin < activerow->buckets[j].xofymin) && (j >= 0))
        {
            activerow->buckets[j + 1].ymin = activerow->buckets[j].ymin;
            activerow->buckets[j + 1].ymax = activerow->buckets[j].ymax;
            activerow->buckets[j + 1].xofymin = activerow->buckets[j].xofymin;
            activerow->buckets[j + 1].xofymax = activerow->buckets[j].xofymax;
            // activerow->buckets[j + 1].numerator = activerow->buckets[j].numerator;
            // activerow->buckets[j + 1].denominator = activerow->buckets[j].denominator;
            // activerow->buckets[j + 1].increment = activerow->buckets[j].increment;
            activerow->buckets[j + 1].minv = activerow->buckets[j].minv;

            j = j - 1;
        }
        activerow->buckets[j + 1].ymin = temp.ymin;
        activerow->buckets[j + 1].ymax = temp.ymax;
        activerow->buckets[j + 1].xofymin = temp.xofymin;
        activerow->buckets[j + 1].xofymax = temp.xofymax;
        // activerow->buckets[j + 1].numerator = temp.numerator;
        // activerow->buckets[j + 1].denominator = temp.denominator;
        // activerow->buckets[j + 1].increment = temp.increment;
        activerow->buckets[j + 1].minv = temp.minv;

    }
}

// Remove edge when its ymax <= y
void removeEdgeByYmax(EdgeTable *activerow,int y){
  int i, flag=0;
  for(i=0;i < activerow->countEdgeBucket; i++){
    if(activerow->buckets[i].ymax <= y ){
      flag=1;
      break;
    }
  }
  if(flag == 1){
    activerow->buckets.erase(activerow->buckets.begin()+i);
    activerow->countEdgeBucket--;
    // cout << "Removed at " << y << endl;
  }
}


void printActiveEdgeTable(EdgeTable *activerow){
  cout << "No. of bucket edges: " << activerow->countEdgeBucket << endl;
  for(int i=0; i < activerow -> countEdgeBucket; i++){
    // cout << endl;
    cout << "Ymin: " << activerow->buckets[i].ymin << endl;
    cout << "Ymax: " << activerow->buckets[i].ymax << endl;
    cout << "xcoordinate of ymin: "<< activerow->buckets[i].xofymin << endl;
    cout << "xcoordinate of ymax: " << activerow->buckets[i].xofymax << endl;
    // cout << "Slope inverse numerator: " << activerow->buckets[i].numerator << endl;
    // cout << "Slope inverse denominator: " << activerow->buckets[i].denominator << endl;
    // cout << "Slope inverse increment: " << activerow->buckets[i].increment << endl;
    cout << "Slope inverse: " << activerow->buckets[i].minv << endl;
  }
}

void printAllEdges(EdgeTable GlobalEdgeTable[windowWidth]){
  int i, count=0;
  for (i=0;i<maxheight; i++){
    // cout << endl;
    if(GlobalEdgeTable[i].countEdgeBucket>0){
      printActiveEdgeTable(&GlobalEdgeTable[i]);
      count++;
    }
    // cout << "Ymax: " << pol.edges[i].ymax << endl;
    // cout << "xcoordinate of ymin: " << pol.edges[i].xofymin << endl;
    // cout << "xcoordinate of ymax: " << pol.edges[i].xofymax << endl;
    // cout << "Slope inverse numerator: " << pol.edges[i].numerator << endl;
    // cout << "Slope inverse denominator: " << pol.edges[i].denominator << endl;
    // cout << "Slope inverse increment: " << pol.edges[i].increment << endl;
  }
  cout << "Total no. of edges: " << count << endl;
}
