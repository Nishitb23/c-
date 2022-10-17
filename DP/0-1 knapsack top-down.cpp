#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int w[],int n,int capacity){
    int dp[n+1][capacity+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=capacity;j++){
        dp[0][j] =0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            int x=0,y=0;
            if(j-w[i-1]>=0){
                x = val[i-1]+dp[i-1][j-w[i-1]];
            }
            y= dp[i-1][j];
            dp[i][j] = max(x,y);
        }
    }
    
    return dp[n][capacity];
}

int main(){
    int val[] = {1,3,4,5,6,9};
    int weight[] = {1,4,5,7,3,2};
    int n=sizeof(val)/sizeof(val[0]);
    int capacity=7;
    
    int maxprofit = knapsack(val,weight,n,capacity);
    cout<<maxprofit;
    
    return 0;
}