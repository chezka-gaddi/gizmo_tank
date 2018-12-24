#include "bfsPaths.h"


BFSPaths::BFSPaths(Graph *G, int v) : s(v)
{
    bfs(G, s);
}


bool BFSPaths::hasPath(int v) { return info[v].marked; }


int BFSPaths::Distance(int v)
{
   return info[v].dist;
}


int BFSPaths::DangerVal(int v)
{
   return info[v].dangerVal;
}


int BFSPaths::inRangeVal(int v)
{
   return info[v].inRange;
}


void BFSPaths::setHeatMapVals(int v, int danger, int range)
{
    info[v].dangerVal += danger;
    info[v].inRange += range;
}


std::list<int> BFSPaths::pathTo(int v)
{
    std::list<int> path;
    if (!hasPath(v)) return path;
    for (int x = v ; x != s ; x = info[x].prev)
        path.push_front(x);
    path.push_front(s);
    return path;
}


void BFSPaths::showPaths(int height, int width, int start)
{
    for (int row = 0 ; row < height ; row++)
    {
        for (int col = 0 ; col < width; col++) 
            if (start == row * width + col) 
                std::cout << setw(3) << "X";
            else
                std::cout << setw(3) << info[row * width + col].dist;
        std::cout << std::endl;
    }
}


void BFSPaths::bfs(Graph *G, int s)
{
   std::queue<int> frontier;
   frontier.push(s);
   info[s].marked = true;
   info[s].dist = 0;
   info[s].dangerVal = 0;
   info[s].inRange = 0;
   while (!frontier.empty())
   {
      int v = frontier.front();
      frontier.pop();
      for (int w : G->adj(v))
      {
         if (!info[w].marked)
         {
            frontier.push(w);
            info[w].marked = true;
            info[w].prev = v;
            info[w].dist = info[v].dist + 1;
         }
      }
   }
}
