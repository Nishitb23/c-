#include<bits/stdc++.h>
using namespace std;

class graph{
  map<int,vector<int>> adj;
  map<int,bool> visited;
  map<int,bool> rec_stack;
  
  public:
  
  void addEdge(int u, int v){
      adj[u].push_back(v);
  }
  
  bool isCycle(int node){
      visited[node] = true;
      rec_stack[node] = true;
      
      for(int next: adj[node]){
          if(!visited[next]){
              if(isCycle(next)){
                  return true;
              }
          }else if(rec_stack[next]){
              return true;
          }
      }
      rec_stack[node] = false;
      return false;
  }
  
  bool checkCycle(){
      
      for(auto itr: adj){
          if(!visited[itr.first]){
              if(isCycle(itr.first)){
                  return true;
              }
          }
      }
      return false;
  }
    
};

int main(){
    
    graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    
    if(g.checkCycle()){
        cout<<"Cycle detected";
    }else{
        cout<<"No Cycle";
    }
    
    return 0;
    
}