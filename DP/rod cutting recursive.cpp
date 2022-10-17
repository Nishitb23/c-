#include<bits/stdc++.h>
using namespace std;

int cutting(int length[],int price[],int n,int total){
    if(n==0||total==0){
        return 0;
    }
    
    if(total-length[n-1]>=0){
       return max(price[n-1]+cutting(length,price,n,total-length[n-1]),cutting(length,price,n-1,total)); 
    }
    return cutting(length,price,n-1,total);
}

int main(){
    
    int length[] = {1,2,3,4,5,6,7,8};
    int price[] = {1,5,8,9,10,17,17,20};
    int n= sizeof(length)/sizeof(length[0]);
    int total = 8;
    cout<<cutting(length,price,n,total);
    
    return 0;
}