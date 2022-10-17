#include<bits/stdc++.h>
using namespace std;

int coinchange(int coins[],int n,int sum){
    if(sum==0){
        return 0;
    }
    if(n==0){
        return INT_MAX;
    }
    if(sum-coins[n-1]>=0)
    return min(1+coinchange(coins,n,sum-coins[n-1]),coinchange(coins,n-1,sum));
    
    return coinchange(coins,n-1,sum);
}

int main(){
    
    int coins[] = {1,2,4};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 6;
    cout<<coinchange(coins,n,sum);
    
    return 0;
}