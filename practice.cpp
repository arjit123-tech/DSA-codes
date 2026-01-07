#include<iostream>
using namespace std;
void updateithbit(int num, int i, int val){
    num=num&~(1<<i);
    num=num|(val<<i);
    cout<<num<<endl;
}
int main(){
    updateithbit(7,2,0);
    return 0;
}