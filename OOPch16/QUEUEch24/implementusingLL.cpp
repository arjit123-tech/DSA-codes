#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Queue{
    Node* frontNode;
    Node* rear;
    public:
    Queue(){
        frontNode=rear=NULL;
    }
    void push(int data){
        Node* newNode=new Node(data);
        if(frontNode==NULL){
            frontNode=rear=newNode;
            return;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp=frontNode;
        frontNode=frontNode->next;
        delete temp;
    }
    public:
        int front(){
            return frontNode->data;
        }
        bool empty(){
            return frontNode==NULL;
        }
};
int main(){
    Queue q;
q.push(1);
q.push(2);
q.push(3);
while(!q.empty()){
    cout<<q.front()<<endl;
    q.pop();
}
    return 0;
}