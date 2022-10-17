#include<bits/stdc++.h>
using namespace std;

int subset(int arr[],int n,int sum){
    
    if(n==0){
        return sum;
    }
     if(sum-2*arr[n-1]>=0){
         return min(subset(arr,n-1,sum-2*arr[n-1]),subset(arr,n-1,sum));
     }   
    return subset(arr,n-1,sum);
}

int main(){
    int arr[] = {1,6,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    cout<<subset(arr,n,sum);
    
    return 0;
}