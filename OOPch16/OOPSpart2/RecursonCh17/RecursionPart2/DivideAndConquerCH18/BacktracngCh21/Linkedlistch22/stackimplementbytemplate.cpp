#include<iostream>
#include<vector>
using namespace std;
template<class T>
class stack{
        vector<T> vec;
        public:
       void push(T val){
            vec.push_back(val);
        }
        void pop(){
           if(isempty()){
            cout<<"stack is empty"<<endl;
            return;


           }
           vec.pop_back();
        }

        T top(){
            // if(isempty()){
            //     cout<<"stack is empty"<<endl;
            //     return -1;
            // }
            int lastidx = vec.size() - 1;
            return vec[lastidx];
        }
        bool isempty(){
           return vec.size()==0;
        }
    };
int  main(){
  //  stack<int>s;
  //now char
  stack<char>s;
    // s.push(4);
    // s.push(3); 
    // s.push(2);
    // s.push(1);
     s.push('a');
      s.push('b');
       s.push('c');
        s.push('d');
    while(!s.isempty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
