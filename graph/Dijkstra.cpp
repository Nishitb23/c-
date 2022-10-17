#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n= 5,scr=0;
    vector<pair<int,int>> adj[n];
    
    adj[0].push_back({1,2});
	adj[0].push_back({3,1});
	adj[1].push_back({0,2});
	adj[1].push_back({4,5});
	adj[1].push_back({2,4});
	adj[2].push_back({1,4});
	adj[2].push_back({3,3});
	adj[2].push_back({4,1});
	adj[3].push_back({0,1});
	adj[3].push_back({2,3});
	adj[4].push_back({1,5});
	adj[4].push_back({2,1});
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	int cost[n];
	memset(cost,INT_MAX,n);
	
	pq.push({0,scr});
	cost[scr] = 0;
	
	while(!pq.empty()){
	    int dist = pq.top().first;
	    int node = pq.top().second;
	    pq.pop();
	    
	    for(auto next: adj[node]){
	        if(dist+next.second<cost[next.first]){
	           cost[next.first] = dist+next.second;
	           pq.push({cost[next.first],next.first});
	        }
	    }
	}
	
	for(int dist: cost){
	    cout<<dist<<" ";
	}
    
    return 0;
}