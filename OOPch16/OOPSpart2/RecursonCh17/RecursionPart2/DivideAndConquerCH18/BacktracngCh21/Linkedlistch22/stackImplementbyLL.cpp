#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;
template<class T>
class stack{
    list<T> ll;
    public:
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    T top(){
        return ll.front();
    }
    bool isempty(){
        return ll.size()==0;
    }
};

int  main(){
    stack<int>s;
  //now char
  //stack<char>s;
     s.push(4);
     s.push(3); 
     s.push(2);
    s.push(1);
    //  s.push('a');
    //   s.push('b');
    //    s.push('c');
    //     s.push('d');
    while(!s.isempty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
