#include<bits/stdc++.h>
using namespace std;

class tree{
  public:
  
  int data;
  tree* left;
  tree* right;
  
  tree(int val){
      data = val;
      left = NULL;
      right = NULL;
  }
};

void levelSpiral(tree* root){
    stack<tree*> s1;
    stack<tree*> s2;
    
    if(root){
        s1.push(root);
    }
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            tree* node = s1.top();
            s1.pop();
            cout<<node->data<<" ";
            if(node->right)
                s2.push(node->right);
            if(node->left)
                s2.push(node->left);
        }
        while(!s2.empty()){
            tree* node = s2.top();
            s2.pop();
            cout<<node->data<<" ";
            if(node->left)
                s1.push(node->left);
            if(node->right)
                s1.push(node->right);
        }
    }
}

int main(){
    
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(7);
    root->left->right = new tree(6);
    root->right->left = new tree(5);
    root->right->right = new tree(4);
    
    levelSpiral(root);
    
    return 0;
}