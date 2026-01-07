#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node* buildtree(vector<int> nodes){
    static int idx=-1;
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    node* newnode=new node(nodes[idx]);
    newnode->left=buildtree(nodes);// for left subtree
    newnode->right=buildtree(nodes);//for right subtree
    return newnode;
}
int height(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return max(leftheight,rightheight)+1;
}
void kthHelper(node* root, int k, int currlevel){
    //base case
    if(root==NULL){
        return;
    }
    if(currlevel==k){
        cout<<root->data<<" ";
        return;
    }
    kthHelper(root->left,k,currlevel+1);
    kthHelper(root->right,k,currlevel+1);
    
}
void kthlevel(node* root, int k){
    kthHelper(root,k,0);
    cout<<endl;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=buildtree(nodes);
    kthlevel(root,3);
    return 0;
}