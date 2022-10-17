// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class graph{
  map<int,vector<int>> edges;
  map<int,bool> visited;
  
  public:
  
  void addEdge(int v, int u){
      edges[v].push_back(u);
      //edges[u].push_back(v);
  }
  
  void dfs(int node){
      visited[node] = true;
      cout<<node<<" ";
      
      for(int next: edges[node]){
          if(!visited[next]){
              dfs(next);
          }
      }
  }
  
};

int main() {
    
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal \n";
       
      // Function call
    g.dfs(2);

    return 0;
}