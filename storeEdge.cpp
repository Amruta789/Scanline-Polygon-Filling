#include "myheader.h"
using namespace std;
// Store an edge in Global Edge Table
void storeEdge(EdgeTable GlobalEdgeTable[640], int x1,int y1, int x2, int y2){
    // horizontal lines are not stored in edge table
    struct Edge ed;
    if (y2==y1)
        return;
    // Check for ymin
    if (y1>y2){
        ed.ymin=y2;
        ed.ymax=y1;
        ed.xofymin=x2;
        ed.xofymax=x1;
    }else{
        ed.ymin=y1;
        ed.ymax=y2;
        ed.xofymin=x1;
        ed.xofymax=x2;
    }
    // ed.numerator = ed.xofymax - ed.xofymin;
    // ed.denominator = ed.ymax - ed.ymin;
    // ed.increment = ed.denominator;

    // Calculate slope inverse of the edge
    ed.minv = ((float)(ed.xofymax - ed.xofymin))/((float)(ed.ymax - ed.ymin));
    GlobalEdgeTable[ed.ymin].countEdgeBucket++;
    // Add edge to the table at the corresponding ymin index
    GlobalEdgeTable[ed.ymin].buckets.push_back(ed);
    // cout << endl;
    // cout << "Ymin: " << ed.ymin << endl;
    // cout << "Ymax: " << ed.ymax << endl;
    // cout << "xcoordinate of ymin: " << ed.xofymin << endl;
    // cout << "xcoordinate of ymax: " << ed.xofymax << endl;
    // cout << "Slope inverse: "<< ed.minv << endl;
    // cout << "Slope inverse numerator: " << ed.numerator << endl;
    // cout << "Slope inverse denominator: " << ed.denominator << endl;
    // cout << "Slope inverse increment: " << ed.increment << endl;

    // Sort the edges according to xofymin in the buckets
    insertionSort(&GlobalEdgeTable[ed.ymin]);
}
