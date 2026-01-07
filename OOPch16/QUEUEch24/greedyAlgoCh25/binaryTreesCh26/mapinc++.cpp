#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    map<int,string> m;
    m[101]="arjit";
    m[102]="ajay";
    m[103]="arjit";
    cout<<m[102]<<endl;
    cout<<m.size()<<endl;
    for(auto it: m){
        cout<<"key="<<it.first<<", "<<"value="<<it.second<<endl;
    }
    return 0;
}