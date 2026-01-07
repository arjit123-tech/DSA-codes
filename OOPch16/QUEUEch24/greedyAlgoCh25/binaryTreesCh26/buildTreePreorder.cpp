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
void preorder(node* root){//for printing tree elements pre order
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    

}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
vector<int> nodes ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node* root =buildtree(nodes);
//cout<<"root data "<<root->data<<endl;
preorder(root);
cout<<endl;
postorder(root);
    return 0;
}