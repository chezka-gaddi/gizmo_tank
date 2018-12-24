#ifndef __GRAPH_H
#define __GRAPH_H

#include <list>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "MapData.h"
#include "constants.h"

using namespace std;

// typedef for adjacency list for map
typedef map<int, set<int> > map_t;


class Graph
{
    protected:
        // An adjacency list representation of the graph
        map_t vertices;
        int numVertices, numEdges;

    public:
        Graph();
        Graph( const vector <vector <int>>& );
        virtual ~Graph() {
        };

        // returns a list of the vertices in the graph
        list<int> Vertices() const;
   
        // returns the adjacency list for a vertex (v)
        set<int> adj(int v);
   
        // Add an edge to the graph
        virtual void addEdge(int, int);

        // accessor returning the number of vertices in the graph
        int V() const;
   
        // accessor returning the number of edges in the graph
        int E() const;
};

#endif
