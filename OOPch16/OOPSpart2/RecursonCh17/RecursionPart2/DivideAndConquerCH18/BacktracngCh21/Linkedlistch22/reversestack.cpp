#include<iostream>
#include<stack>
using namespace std;
void pushatbottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp=s.top();
    s.pop();
    pushatbottom(s, val);
    s.push(temp);
}
void reversestack(stack<int> s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reversestack(s);
    pushatbottom(s,temp);
}
void printstack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    printstack(s);
    reversestack(s);
    printstack(s);
    return 0;
}