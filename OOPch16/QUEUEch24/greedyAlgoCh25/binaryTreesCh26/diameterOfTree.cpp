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

int diameter1(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    int leftdiameter=diameter1(root->left);
    int rightdiameter=diameter1(root->right);
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    int selfdiameter=leftheight+rightheight+1;
    return max(selfdiameter,max(leftdiameter,rightdiameter));
}
pair<int,int> diam2(node* root){
    if(root == NULL) {
        return {0, 0}; // {diameter, height}
    }
    pair<int, int> leftinfo = diam2(root->left);
    pair<int, int> rightinfo = diam2(root->right);
    int currdiam = leftinfo.second + rightinfo.second + 1;
    int finaldiam = max(currdiam, max(leftinfo.first, rightinfo.first));
    int currheight = max(leftinfo.second, rightinfo.second) + 1;
    return {finaldiam, currheight};
}
int main(){
     vector<int> nodes ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
     cout<<"Diameter1 of the tree is "<<diameter1(buildtree(nodes))<<endl;
     cout<<"Diameter2 of the tree is "<<diam2(buildtree(nodes)).first<<endl;
    return 0;
}