#include<bits/stdc++.h>
using namespace std;

class graph{
    map<int,vector<int>> adj;
    map<int,bool> visited;
    stack<int> st;
    
    public:
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
    void topologicalSort(int node){
        
        visited[node]= true;
        for(int next: adj[node]){
            if(!visited[next]){
                topologicalSort(next);
            }
        }
        st.push(node);
        
    }
    
    void sort(){
        for(auto it: adj){
            if(!visited[it.first]){
                topologicalSort(it.first);
            }
        }
        
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    
};

int main(){
    
    graph g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    g.sort();
    
    return 0;
}