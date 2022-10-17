#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int w[],int n,int capacity){
    if(n==0||capacity==0){
        return 0;
    }
    int x=0,y=0;
    if(w[n-1]<=capacity){
        x=val[n-1]+knapsack(val,w,n-1,capacity-w[n-1]);
    }
    y= knapsack(val,w,n-1,capacity);
    return max(x,y);
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