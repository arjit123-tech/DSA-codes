#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class list{
    Node* head;
    Node* tail;
    public:
    list(){
        head=NULL;
        tail=NULL;
    }
    // getters to access private members safely
    Node* getHead(){
        return head;
    }
    Node* getTail(){
        return tail;
    }
    void push_front(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }
    void push_back(int val){
        Node* newnode=new Node(val);

        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void printlist(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
    //inertion of new node in link list 
    void insert(int val, int pos){
         Node*newnode=new Node(val);
         if(pos==0){
             newnode->next = head;
             head = newnode;
             if(tail==NULL) tail = newnode;
             return;
         }
         Node*temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"position is invalid"<<endl;
                return;
            }
            temp=temp->next;
        }
         //temp is now at pos-1 that is prev/left
         newnode->next=temp->next;
         temp->next=newnode;
         if(newnode->next==NULL) tail=newnode;
    }
    void pop_front(){
        if(head==NULL){
            cout<<"ll is empty";
            return ;
        }
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        Node*temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    int searchitr(int key){
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;

            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
    int helper (Node*temp, int key ){
        if(temp==NULL){
            return -1;
        }
        if (temp->data==key){
            return 0;
        }
       int idx= helper(temp->next,key);
       if(idx==-1){
        return -1;
       }
       return idx+1;
    }
    int searchrecursion(int key){
        return helper(head,key);
    }
    void reverse(){
        Node*curr=head;
        Node*prev=NULL;
        while(curr!=NULL){
            Node*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

        }
        head=prev;
    }
    void removenth(int n){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        // compute size
        int sz = 0;
        Node* temp = head;
        while(temp != NULL){    
            sz++;
            temp = temp->next;
        }
        if(n <= 0 || n > sz){
            cout<<"Invalid n"<<endl;
            return;
        }
        // if we need to remove the head (nth from end where n == sz)
        if(n == sz){
            Node* toDel = head;
            head = head->next;
            if(head == NULL) tail = NULL;
            cout<<"going to delete"<<toDel->data<<endl;
            delete toDel;
            return;
        }
        Node* prev = head;
        for(int i = 1; i < (sz - n); i++){
            prev = prev->next;
        }
        Node* toDel = prev->next;
        cout<<"going to delete"<<toDel->data<<endl;
        prev->next = toDel->next;
        if(prev->next == NULL) tail = prev;
        delete toDel;
    }
};
bool isCycle(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"cycle exist"<<endl;
            return true;
        }
        
    } 
    return false;
}
void removecycle(Node*head){
    Node*slow=head;
    Node*fast=head;
    bool iscycle=false;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"cycle is exist\n";
            iscycle=true;
            break;
        }
    }
    if(iscycle){
        cout<<"cycle not exist\n";
        return;
    }
    slow=head;
    if(slow==fast){
        while(fast->next!=NULL){
            fast=fast->next;
        }
        fast->next=NULL;
    }else{
        Node*prev=fast;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=NULL;
    }
}

int main(){
    list ll;
    ll.push_front(5);
    ll.push_front(4);
     ll.push_front(3);
     ll.push_front(2);
//    ll.getTail()->next = ll.getHead();
//    isCycle(ll.getHead());
    // ll.insert(100,2);
    // ll.printlist();
    // ll.pop_front();
   // ll.removenth(2);
   // ll.printlist();
//    ll.getTail()->next = ll.getHead();
  // isCycle(ll.getHead());
  ll.getTail()->next = ll.getHead();
  removecycle(ll.getHead());
  ll.printlist();
    return 0;
}