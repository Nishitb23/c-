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

int search(int pre[], int num, int n){
    for(int i=0;i<n;i++){
        if(pre[i]==num){
            return i;
        }
    }
    
    return -1;
}

tree* constructTree(int in[], int pre[], int n){
    tree* node = new tree(pre[0]);
    int index = search(in,pre[0],n);
    if(index!=0){
        node->left = constructTree(in, pre+1, index);
    }
    if(index!=n-1){
        node->right = constructTree(in+index+1,pre+index+1,n-index-1);
    }
    return node;
}

void inorder(tree* node){
    if(node){
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}

void preorder(tree* node){
    if(node){
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(tree* node){
    if(node){
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
}

int main()
{
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    tree* root = constructTree(in, pre, n);
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    return 0;
}