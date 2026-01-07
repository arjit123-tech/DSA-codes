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
void topview(node* root){
    queue<pair<node*,int>> q;// node.hd
    map<int,int> m;//hd,node->data
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> curr=q.front();
        q.pop();

        node* currnode=curr.first;
        int currhd=curr.second;
        //check if currhd is present in map or not
        if(m.count(currhd)==0){
            m[currhd]=currnode->data;
        }
        if(currnode->left!=NULL){
            pair<node*,int> leftpair=make_pair(currnode->left,currhd-1);
            q.push(leftpair);
        }
        if(currnode->right!=NULL){
            pair<node*,int> rightpair=make_pair(currnode->right,currhd+1);
            q.push(rightpair);
         }
    }
    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> nodes ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root=buildtree(nodes);
    topview(root);
    return 0;
}