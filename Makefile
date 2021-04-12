CXX = g++ -Wall
CXXFLAGS = -c -g
LDFLAGS = -lglut -lGLU -lGL -lm
OBJECTS = main.o parsePolygons.o myInit.o display.o activeEdgeFunctions.o ScanlineFill.o storeEdge.o

main: $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(LDFLAGS)
display.o: display.cpp
		$(CXX) $(CXXFLAGS) display.cpp $(LDFLAGS)
parsePolygons.o: parsePolygons.cpp
	$(CXX) $(CXXFLAGS) parsePolygons.cpp
myInit.o: myInit.cpp
	$(CXX) $(CXXFLAGS) myInit.cpp $(LDFLAGS)
activeEdgeFunctions.o: activeEdgeFunctions.cpp
	$(CXX) $(CXXFLAGS) activeEdgeFunctions.cpp $(LDFLAGS)
ScanlineFill.o: ScanlineFill.cpp
	$(CXX) $(CXXFLAGS) ScanlineFill.cpp $(LDFLAGS)
storeEdge.o: storeEdge.cpp
	$(CXX) $(CXXFLAGS) storeEdge.cpp $(LDFLAGS)
# sortalledges.o: sortalledges.cpp
# 	$(CXX) $(CXXFLAGS) sortalledges.cpp $(LDFLAGS)

$(OBJECTS): myheader.h
