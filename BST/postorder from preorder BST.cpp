#include<bits/stdc++.h>
using namespace std;

void postOrder(int pre[], int n, int& preIndex, int min, int max){
    if(preIndex==n || pre[preIndex]<min || pre[preIndex]>max){
        return;
    }
    int node = pre[preIndex++];
    postOrder(pre,n,preIndex,min,node);
    postOrder(pre,n,preIndex,node,max);
    cout<<node<<" ";
}

int main(){
    int pre[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre)/sizeof(pre[0]);
    int preIndex=0;
    postOrder(pre,n,preIndex,INT_MIN,INT_MAX);
    
    return 0;
}