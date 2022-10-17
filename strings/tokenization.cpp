#include<bits/stdc++.h>
using namespace std;

int main(){
    char ch[] = "Nishit Bhardwaj";
    string name(ch);
    vector<string> v;
    
    stringstream ss(name);
    string flag;
    while(getline(ss,flag,' ')){
        v.push_back(flag);
    }
    
    for(string s:v){
        cout<<s<<"\n";
    }
    
    for(int i=0;i<name.size();i++){
        cout<<name[i]<<" ";
    }
}