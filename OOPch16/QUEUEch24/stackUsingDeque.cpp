#include<iostream>
#include<deque>
using namespace std;
class stack{
    deque<int> deq;
public:
    void push(int data){
        deq.push_back(data);
    }
    void pop(){
        deq.pop_back();
    }
    int top(){
        return deq.back();
    }
    bool empty(){
        return deq.empty();
    }
};

int main(){
    stack q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }

    return 0;
}