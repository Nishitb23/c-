#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[],int n,int target){
    bool dp[n+1][target+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]= true; 
    }
    for(int i=1;i<=target;i++){
        dp[0][i]= false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j-arr[i-1]>=0)
            dp[i][j]= dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][target];
}

int main(){
    int arr[]= {2,3,7,8,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    int target= 11;
    
    if(subsetSum(arr,n,target)){
        cout<<"Found\n";
    }else{
        cout<<"Not Found\n";
    }
    
    return 0;
}