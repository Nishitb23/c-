#include<bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2,int n,int m){
    if(n==0||m==0){
        return "";
    }
    if(s1[n-1]==s2[m-1]){
        return lcs(s1,s2,n-1,m-1)+s1[n-1];
    }
    string o1 = lcs(s1,s2,n-1,m);
    string o2 = lcs(s1,s2,n,m-1);
    if(o1.size()>=o2.size()){
        return o1;
    }
    return o2;
}

int main(){
    string s1 = "abcdghalsr";
    string s2 = "abedfhr";
    int n = s1.size();
    int m = s2.size();
    
    cout<<lcs(s1,s2,n,m);
    
    return 0;
}