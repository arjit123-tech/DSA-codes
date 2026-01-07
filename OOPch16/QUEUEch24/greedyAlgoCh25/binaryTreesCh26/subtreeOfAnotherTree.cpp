#include<iostream>
#include<vector>
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
    bool isIdentical(node* root1, node* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }else if(root1==NULL|| root2==NULL){
            return false;
        }
        if (root1->data != root2->data){
            return false;
        }
        return isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right);
        
    }
    bool isSubtree(node* root, node* subroot){
        if(root==NULL && subroot==NULL){
            return true;
        }else if(root==NULL|| subroot){
            return false;
        }
        if(root->data==subroot->data){
           if (isIdentical(root,subroot)){
            return true;
           }
        }
        int isleftsubtree=isSubtree(root->left,subroot);
        if(!isleftsubtree){
            return isSubtree(root->right,subroot);
        }
        return true;
    }
int main(){
    vector<int> nodes ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* subroot=new node(2);
    subroot->left=new node(4);
    subroot->right=new node(5);
    node* root=buildtree(nodes);
    cout<<isSubtree(root,subroot)<<endl;
    cout<<isIdentical(root,subroot)<<endl;
    return 0;
}