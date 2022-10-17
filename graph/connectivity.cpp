#include<bits/stdc++.h>
using namespace std;

bool searchDFS(vector<int> adj[],bool visited[], int node, int dest){
    if(node == dest){
        return true;
    }
    visited[node]=true;
    
    for(auto next: adj[node]){
        if(!visited[next]){
            if(searchDFS(adj,visited,next,dest)){
                return true;   
            }
        }
    }
    
    return false;
}

int main(){
    int n=4;
    vector<int> adj[n];
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    
    bool visited[n];
    memset(visited,false,n);
    
    cout<<searchDFS(adj,visited,3,1);
    
    return 0;
}