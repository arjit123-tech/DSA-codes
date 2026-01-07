#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
bool isvalid(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch=='('||ch=='['||ch=='{'){
            s.push(ch);
        }else{//closing
            if(s.empty()){
                return false;
            }
            int top=s.top();

            if(top=='('&&ch==')'||top=='['&&ch==']'||top=='{'&&ch=='}'){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return s.empty();
    
}
//duplicate parentheses code
bool isduplicate(string str){
    stack<char>s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch!=')'){
            s.push(ch);
        }else{//closing
           if(s.top()=='(') {
            return false;//duplicate
           }
           while(s.top()!='('){
            s.pop();
           }
           s.pop();
        }
    }
    return false;
}
void printarr(vector<int>vec){
    for (int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
void maxareahistogram(vector<int>height){
    int n = height.size();
    vector<int>nsl(n);
    vector<int>nsr(n);
    stack<int>s;
    //next smaller left
    nsl[0]=-1;
    s.push(0);
    for(int i=1;i<n;i++){
        int curr=height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i]=-1;
        }else{
            nsl[i]=s.top();
        }
        s.push(i);
    }
    //next smaller right
   printarr(nsl);
    while(!s.empty()){
        s.pop();
    }
    s.push(n-1);
    nsr[n-1]=n;
    for(int i=n-2;i>=0;i--){
        int curr=height[i];
        while(!s.empty()&&curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=n;
        }else{
            nsr[i]=s.top();
        }
        s.push(i);
    }
    int maxarea=0;
    for(int i=0;i<n;i++){
        int ht=height[i];
        int width=nsr[i]-nsl[i]-1;
        int area=ht*width;
        maxarea=max(maxarea,area);
    }
    cout<<"max area of histogram"<<maxarea<<endl;
    
}
int main(){
    // string str1="([}])";//invalid=false
    // string str2="([{}])";//valid=true
    // cout<<isvalid(str1)<<endl;//false=0
    // cout<<isvalid(str2)<<endl;//true=1
    // string str1="((a+b))";
    // string str2="((a+b)+(c+d))";
    // cout<<isduplicate(str1)<<endl;//true=1
    // cout<<isduplicate(str2)<<endl;//false=0
    //histogram from here
    vector<int>height={2,1,5,6,2,3};
    maxareahistogram(height);
    return 0;
}