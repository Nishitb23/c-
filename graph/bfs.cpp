#include<bits/stdc++.h>
using namespace std;

class graph{
  map<int,vector<int>> adj;
  map<int,bool> visited;
  
  public:
  
  void addEdge(int v,int u){
      adj[v].push_back(u);
  }
  
  void bfs(int node){
      
      queue<int> q;
      q.push(node);
      
      while(!q.empty()){
          node = q.front();
          q.pop();
          if(!visited[node]){
              if(!visited[node]){
                  visited[node] = true;
                  cout<<node<<" ";
                  for(int next: adj[node]){
                      q.push(next);
                  }
              }
          }
      }
  }
  
};

int main(){
    
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
    
    return 0;
}