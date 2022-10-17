#include<bits/stdc++.h>
using namespace std;

int main(){
	int N=5;
	vector<pair<int,int> > adj[N]; 


	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
	
    int parent[N],key[N];
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    set<int> mst;
    
    memset(key,INT_MAX,N);
    pq.push({0,0});
    key[0] = 0;
    parent[0]= -1;
    
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        mst.insert(node);
        
        for(auto next: adj[node]){
            if(mst.find(next.first)==mst.end() && key[next.first]>next.second){
                key[next.first]=next.second;
                parent[next.first]=node;
                pq.push({next.second,next.first});
            }
        }
    }
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n";
    
	return 0;
}