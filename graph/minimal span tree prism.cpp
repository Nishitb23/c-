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
    unordered_set<int> mst;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    memset(key,INT_MAX,N);
    parent[0] = -1;
    key[0]= 0;
    pq.push({0,0});
    
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        mst.insert(node);
        
        for(auto p: adj[node]){
            int next = p.first;
            int wt = p.second;
            if(mst.find(next)==mst.end()){
                if(wt<key[next]){
                    parent[next] = node;
                    key[next] = wt;
                    pq.push({wt,next});
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<i<<" -> "<<parent[i]<<endl;
    }
    
	return 0;
}
