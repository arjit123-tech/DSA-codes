#include<iostream>
#include<vector>
#include<queue>
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
void levelorder(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}
node* buildTree(vector<int>& nodes, int& idx) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        idx++;
        return NULL;
    }
    node* newNode = new node(nodes[idx++]);
    newNode->left = buildTree(nodes, idx);
    newNode->right = buildTree(nodes, idx);
    return newNode;
} 

int main(){
    vector<int> nodes ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int idx = 0;
    node* root = buildTree(nodes, idx);
    levelorder(root);
    return 0;
}