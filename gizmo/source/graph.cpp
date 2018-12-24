/***************************************************************************//**
 * @file
 * @brief Contains functions to create and upkeep Graph.
 ******************************************************************************/

#include "graph.h"

// Macros to help with repeated conditions
#define validRow(r) (r >= 0 && r < height)
#define validCol(c) (c >= 0 && c < width)

#define canEnter(r,c,i) (validRow(r) && validCol(c) && grid[i] != ROCK && grid[i] != WATER && grid[i] != CRATER)


Graph::Graph() { }  // for the derived types


/***************************************************************************//**
 * @author Chezka Gaddi
 * @brief Constructor
 *
 * Creates a Graph given a map.
 *
 * @param[in] Map - map to convert into a graph.
 * @param[in] width - width of map
 * @param[in] height - height of map
 * @return none
 ******************************************************************************/
Graph::Graph( const vector< vector <int>> &Map )
{
    int width = Map.size();
    int height = Map[0].size();
    std::vector <int> grid;

    for( int row = 0; row < height; row++ )
    {
        for( int col = 0; col < width; col++ )
            grid.push_back( Map[col][row] );
    }

    for (int row = 0 ; row < height ; row++)
    {
        for (int col = 0 ; col < width ; col++)
        {
            int index = row * width + col;
            if (!canEnter(row, col,index)) continue;
            if (canEnter(row,col+1,index+1)) addEdge(index, index+1);
            if (canEnter(row,col-1,index-1)) addEdge(index, index-1);
            if (canEnter(row+1,col,index+width)) addEdge(index, index+width);
            if (canEnter(row-1,col,index-width)) addEdge(index, index-width);
            if (canEnter(row+1,col+1,index+width+1)) addEdge(index, index+width+1);
            if (canEnter(row+1,col-1,index+width-1)) addEdge(index, index+width-1);
            if (canEnter(row-1,col+1,index-width+1)) addEdge(index, index-width+1);
            if (canEnter(row-1,col-1,index-width-1)) addEdge(index, index-width-1);
        }
    }
            
    numVertices = vertices.size();
    numEdges = 0;
    
    // For each vertex, count the adjacent vertices to get total edges
    for (int v : Vertices())
        numEdges += adj(v).size();
}



/***************************************************************************//**
 * @brief Return the number of vertices in the graph
 *
 * @return integer representing the number of vertices in the graph
 ******************************************************************************/

int Graph::V() const { return numVertices ; }



/***************************************************************************//**
 * @brief Return the number of edges in the graph
 *
 * @return integer representing the number of edges in the graph
 ******************************************************************************/

int Graph::E() const { return numEdges ; }




/***************************************************************************//**
 * @brief Return the list of vertex names
 *
 * @return a list of strings representing the vertex names in the graph
 ******************************************************************************/

list<int> Graph::Vertices() const
{
    list <int> retList;
    for (auto item : vertices)
        retList.push_back(item.first);
    return retList;
}



/***************************************************************************//**
 * @brief Return the set of vertices adjacent to vertix v
 *
 * @param[in] v - The vertex to which the adjacency list belongs
 * @return a list of strings representing the vertices adjacent to v
 ******************************************************************************/

set<int> Graph::adj(int v)
{
   return vertices[v];
}



/***************************************************************************//**
 * @brief Add an edge to the graph
 *
 * @par Description
 *    This is the default addEdge method which implements the addition of an
 * undirected edge.
 *
 * @param[in] v - The vertex at the origin of the edge
 * @param[in] w - The vertex at the destination of the edge
 ******************************************************************************/

void Graph::addEdge(int v, int w)
{
    vertices[v].insert(w);
    vertices[w].insert(v);
}
