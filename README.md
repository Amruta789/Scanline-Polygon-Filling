# Scanline-Polygon-Filling
This will work as long as OpenGL libraries are installed with C++ in a Linux environment.
The input is a file containing the following format.
```
#no.ofvertices  red green blue
#x-coordinate y-coordinate
```
Multiple polygons can be given with a new line separating each polygon specification. \
\
The basic idea of the algorithm is to draw horizontal lines from the bottom to the top within the borders of each polygon, filling it with that color.
Simply put, the algorithm is as follows:
1. Draw the polygons using `GL_LINE_LOOP` in OpenGL.
2. Store the edges of each polygon in a Global Edge Table. A global edge table is a bucket-sorted list of all edges, sorted according to their minimum y-coordinate. Every edge contains a 'ymin', and a 'ymax'. Horizontal edges are not stored in the table. An array is created with size equal to the maximum height of the window. Within that array, at the index equal to a certain 'ymin', a vector containing all edges with that 'ymin' is stored. The other details related to that edge, such as x-coordinates of ymin and ymax, and the inverse of the slope of that edge are stored as well.
3. The Global Edge Table is required to make the active edge table for scanline filling. To draw a horizontal line, you need the start and end points. The start and end points would be intersections with each edge. However, each time a scanline is drawn, not all the edges of the polygon are considered. Only the edges with a certain ymin are considered for that scanline. Active Edge Table contains all edges with that particular ymin.
```
for y=0 to maximum height of the polygon:
  Check if GlobalEdgeTable[y] has some edges, and move them into the active edge table.
  Remove any edge in AET where the ymax of the edge <= y. This is because if ymax <= y, then the scanline filling with that edge is already finished and no longer required.
  Sort the edges in the active edge table according to x-coordinate of ymin.
  Fill up pairs of edges in AET.
  Update x-coordinate of ymin by adding slope inverse to it.
```

The polygon will be filled up and displayed in the Graphics window.
 
    
  
