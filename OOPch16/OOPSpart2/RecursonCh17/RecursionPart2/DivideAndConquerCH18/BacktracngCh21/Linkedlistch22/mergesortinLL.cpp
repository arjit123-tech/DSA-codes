#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    // You can add other methods as needed
};

Node* merge(Node* left, Node* right){
    LinkedList ans;
    Node* i = left;
    Node* j = right;
    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_front(i->data);
            i = i->next;
        }else{
            ans.push_front(j->data);
            j = j->next;
        }
    }
    while(i != NULL){
        ans.push_front(i->data);
        i = i->next;
    }
    while(j != NULL){
        ans.push_front(j->data);
        j = j->next;
    }
    return ans.head;
}

Node* splitatmid(Node* head){ //this will split ll in two parts 
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL){
        prev->next = NULL;
    }
    return slow;
}

Node* mergesort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* righthead = splitatmid(head);
    Node* left = mergesort(head);
    Node* right = mergesort(righthead);
    return merge(left, right);
}

void printlist(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}
// yahan se zig zag ll ka code h 
Node*reverse(Node*head){
    Node*prev=NULL;
    Node*curr=head;
    Node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
Node* zigzagll(Node*head){
 Node* righthead=splitatmid(head);
 Node*rightheadrev=reverse(righthead);
 //now alternate merging 
Node*left=head;
Node*right=rightheadrev;
Node*tail=right;
while(left!=NULL&&right!=NULL){
    Node*nextleft=left->next;
    Node*nextright=righthead;
    left->next=right;
    right->next=nextleft;
    tail=right;
    left=nextleft;
    right=nextright;
}
if(right!=NULL){
    tail->next=right;
}
return head;
}

int main(){
    LinkedList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    printlist(ll.head);
   // ll.head=mergesort(ll.head);
    ll.head=zigzagll(ll.head);
      printlist(ll.head);
    return 0;
}