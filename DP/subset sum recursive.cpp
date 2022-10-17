#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[],int n,int target){
    if(target==0){
        return true;
    }
    if(n==0){
        return false;
    }
    return subsetSum(arr,n-1,target-arr[n-1])||subsetSum(arr,n-1,target);
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