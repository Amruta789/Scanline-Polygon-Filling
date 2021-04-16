#ifndef MYHEADER_H
#define MYHEADER_H
#define windowWidth 640
#define windowHeight 480
#include<bits/stdc++.h>
#include<GL/glut.h>

// Stores edge of a polygon
struct Edge{
    float xofymin; // x-coordinate of y minimum
    int ymin; // ymin
    int xofymax; // x-coordinate of y maximum
    int ymax; // y max
    // int numerator; // for integer calculations of slope, numerator, denominatora and increment are stored
    // int denominator;
    // int increment;
    float minv; // Slope inverse of this edge
};

struct EdgeTable{
    int countEdgeBucket; // Total no. of edges in the active edge table
    std::vector<Edge> buckets; // List of edges in the table
};

struct Polygons{
  int polygonsnumber; // No. of polygons
  std::vector<int> verticesnumbers; // List of number of vertices in each polygon
  std::vector<float> reds; // Lists of reds, greens, blues in RGB values of each polygon
  std::vector<float> greens;
  std::vector<float> blues;
  std::vector<int> xcoordinates; // List of all x-coordinates of all polygons
  std::vector<int> ycoordinates; // List of all y-coordinates of all polygons
};

extern struct Polygons pol;
// Variable to store the maximum of all ycoordinates, to get the maxheight of the window
extern int maxheight;

// Initializing the Graphics window
void myInit(void);
// Stores the polygon details in the Polygons struct.
void parsePolygons(std::string filename);
// Draws the polygons, reads all vertices to edges, and fills the polgons.
void display(void);
// Stores an edge given as input into the global edge table.
void storeEdge(EdgeTable GlobalEdgeTable[windowWidth],int x1,int y1, int x2, int y2);
// Fills the polygon with the given color
void ScanlineFill(EdgeTable GlobalEdgeTable[windowWidth], float red, float green, float blue);
// Does insertion sort on an active edge table row, sorts according to xofymin
void insertionSort(EdgeTable *activerow);
// Removes edges from the active edge table whose ymax <= y.
void removeEdgeByYmax(EdgeTable *activerow,int y);
// Prints all edges in the active edge table.
void printActiveEdgeTable(EdgeTable *activerow);
// Prints all edges in the global edge table.
void printAllEdges(EdgeTable GlobalEdgeTable[windowWidth]);

#endif
