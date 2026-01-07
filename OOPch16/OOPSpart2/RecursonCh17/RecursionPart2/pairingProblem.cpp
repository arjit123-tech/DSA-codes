#include<iostream>
using namespace std;
int pairing(int n){
    if(n==1||n==2){
        return n;
    }
   return pairing(n-1)+(n-1)*pairing(n-2);
}
int main(){
    cout<<pairing(3)<<endl;
    return 0;
}
//output show the number of pairs for 3 people