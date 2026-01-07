#include<iostream>
using namespace std;
bool ispowerof2(int num){
    if(!(num &(num-1))){
        return true;
    }else{
        return false;
    }
}
int main(){
    cout<<ispowerof2(4)<<endl;
    cout<<ispowerof2(16)<<endl;
    cout<<ispowerof2(13)<<endl;
    cout<<ispowerof2(7)<<endl;
    
    return 0;
}