#include<bits/stdc++.h>
#include <GL/glut.h>
#include "myheader.h"
using namespace std;

// returns number of words in str
int countWords(string str)
{
    int state = 0;
    int wc = 0; // word count

    // Scan all characters one by one
    for(size_t i=0;i<str.length();i++){
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i]=='\r'){
            state = 0;
        }else if (state == 0){
            state = 1;
            wc++;
        }
    }
    // cout << "Word count: " << wc << endl;
    return wc;
}


void parsePolygons(string filename){
  ifstream MyReadFile(filename);
  if(!MyReadFile.is_open()){
    cout << "File does not exist." << endl;
    exit(1);
  }
  string myText;
  pol.polygonsnumber=0;
  while (getline (MyReadFile, myText)) {
    // Ignore comments and empty lines
    if(myText[0]=='#' || myText.length()<=1){
      continue;
    }
    cout << myText << endl;
    // cout << myText.length() << endl;
    int verticesnumber;
    float red, green, blue;
    // Read no. of vertices and RGB values.
    if(countWords(myText)!=4){
      cout << "Error in input file. No. of vertices and RGB values may not have been specified in the correct format." << endl;
      exit(1);
    }

    sscanf(myText.c_str(), "%d %f %f %f", &verticesnumber,&red,&green,&blue);
    pol.polygonsnumber++;
    pol.verticesnumbers.push_back(verticesnumber);
    pol.reds.push_back(red);
    pol.greens.push_back(green);
    pol.blues.push_back(blue);
    // int c = pol.polygonsnumber - 1;
    // cout << pol.verticesnumbers[c] << " " << pol.reds[c] << " " << pol.greens[c] << " " << pol.blues[c] << endl;
    for (int i = 0; i < verticesnumber; i++) {
      getline(MyReadFile,myText);
      if(myText[0]=='#' || myText.length()<=1){
        i--;
        continue;
      }
      cout << myText << endl;
      // cout << myText.length() << endl;
      // cout << i << endl;
      int x,y;
      if(countWords(myText)!=2){
        cout << "Error in input file. X-Y coordinates may not have been specified in the correct format." << endl;
        exit(1);
      }
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
