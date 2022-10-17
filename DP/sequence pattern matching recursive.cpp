#include<bits/stdc++.h>
using namespace std;

bool pattern(string a, string b,int n,int m){
    if(n==0){
        return true;
    }
    if(m==0){
        return false;
    }
    
    if(a[n-1]==b[m-1]){
        return pattern(a,b,n-1,m-1);
    }
    return pattern(a,b,n,m-1);
}

int main(){
    string a = "AXY";
    string b = "ADXCPY";
    cout<<pattern(a,b,a.size(),b.size());
    
    return 0;
}