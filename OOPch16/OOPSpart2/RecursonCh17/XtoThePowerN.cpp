#include<iostream>
using namespace std;
int power(int x, int n){
    if(n == 0) return 1;
    int halfpower = power(x, n/2);
    if(n % 2 == 0) {
        return halfpower * halfpower;
    } else {
        return x * halfpower * halfpower;
    }
}
int main(){
    cout<<power(2,10)<<endl;
    return 0;
}