#ifndef __BFSPATHS_H
#define __BFSPATHS_H

#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

#include "graph.h"

struct Info
{
    bool marked;    /// Has the vertex been marked
    int dist;       /// What is the distance from the start to this vertex
    int prev;       /// From which vertex was this vertex discovered
    
    int dangerVal;  ///
    int inRange;    ///
    int obsRange;   ///

    Info() : marked(false), dist(0), prev(-1), dangerVal(0), inRange(0), obsRange(0) {}
};

class BFSPaths
{
    //map<int, Info> info;
    //int s;                      /// The start node in the Graph G

public:
    map <int, Info> info;
    int s;                      /// The start node in the Graph G
    
    
    BFSPaths(Graph *G, int start);
    void bfs(Graph *G, int start);              /// Breadth-first search
    bool hasPath(int vertex);
    std::list<int> pathTo(int vertex);
    
    int Distance(int vertex);
    int DangerVal(int vertex);
    int inRangeVal(int vertex);
    
    void setHeatMapVals(int vertex, int dangerVal, int inRange );
    void showPaths(int r, int c, int m);
};

#endif
