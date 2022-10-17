#include<bits/stdc++.h>
using namespace std;

int coinchange(int coins[],int n,int sum){
    if(n==0){
        if(sum==0){
            return 1;
        }else{
            return 0;
        }
    }
    if(sum-coins[n-1]>=0)
    return coinchange(coins,n,sum-coins[n-1]) + coinchange(coins,n-1,sum);
    
    return coinchange(coins,n-1,sum);
}

int main(){
    
    int coins[] = {1,2,3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 5;
    cout<<coinchange(coins,n,sum);
    
    return 0;
}