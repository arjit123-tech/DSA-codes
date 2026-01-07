#include<iostream>
 using namespace std;
 void oddeven(int num){
    if(!(num&1)){
        cout<<"Odd Number"<<endl;
    }
    else{
        cout<<"Even Number"<<endl;
    }
 }
 int main(){
 oddeven(5);
 oddeven(8);
    return 0;
 }