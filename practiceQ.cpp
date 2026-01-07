#include<iostream>
using namespace std;
void clearbits(int num, int i){
    int bitmask=(~0)<<i;
    num=num & bitmask;
    cout<<num<<endl;
}
int main(){
    clearbits(15,2);
    return 0;
}