#include <iostream>
#include <list>
using namespace std;


class Graph{

  // No.of vertices
  int V;

  // Pointer to an array contaning adjacency list
  list<int> *adj;

  public:
  Graph(int V); // Constructor

  // Func to add edge to the graph
  void addEdge(int v, int w);

  // prints BFS travel from a point
  bool isRoute(int s, int d);
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
  // add w to v's list
  adj[v].push_back(w);
}

bool Graph::isRoute(int s, int d){

  // base case
  if(s == d) return true;

  // Mark all nodes as not visited
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++){
    visited[i] = false;
  }

  // Create a queue for BFS(not real c++ queue)
  // actually using a list as queue here, becoz list as empty() func to use
  list<int> queue;

  // mark current node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);

  // create a list iterator
  list<int>::iterator i;

  while(!queue.empty()){

    // dequeue a vertex from queue and print it
    s = queue.front();
    queue.pop_front();

    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    for(i = adj[s].begin(); i != adj[s].end(); ++i){
      // i will be the pointer to the neighbours
      // value of i, v=can be received using *i
      if(*i == d)
        return true;

      else if(!visited[*i]){
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
  return false;
}

int main() {
     
   // Create a graph 
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

        int u = 1, v = 3;
    if(g.isRoute(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
  
    u = 3, v = 1;
    if(g.isRoute(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
}
