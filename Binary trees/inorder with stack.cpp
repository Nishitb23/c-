#include<bits/stdc++.h>
using namespace std;

class tree{
  public:
  
  int data;
  tree* left;
  tree* right;
  
  tree(int data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

tree* insert(tree* root, int val){
    
    if(root==NULL){
        root= new tree(val);
    }else{
        
        queue<tree*> q;
        q.push(root);
        while(!q.empty()){
            tree* current = q.front();
            q.pop();
            if(!current->left){
                current->left= new tree(val);
                break;
            }else if(!current->right){
                current->right= new tree(val);
                break;
            }else{
                q.push(current->left);
                q.push(current->right);
            }
        }
    }
    
    return root;
}

void inorder(tree* node){
    if(node){
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}

void inorderStack(tree* node){
    stack<tree*> st;
    
    while(node || !st.empty()){
        while(node){
            st.push(node);
            node = node->left;
        }
        node = st.top();
        cout<<node->data<<" ";
        st.pop();
        node = node->right;
    }
}

int main(){
    
    tree* root = insert(NULL,1);
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,5);
    
    inorder(root);
    cout<<endl;
    inorderStack(root);
    return 0;
}