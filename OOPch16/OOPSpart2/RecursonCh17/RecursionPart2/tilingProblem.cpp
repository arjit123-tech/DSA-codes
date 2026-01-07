#include<iostream>
using namespace std;
int tilingproblem(int n){
    if(n==0||n==1){//base case
        return 1;
    }
    int ans1=tilingproblem(n-1);//vertical 2xn-1
    int ans2=tilingproblem(n-2);//horizontal 2xn-2
    return ans1+ans2;
}
int main(){
    int n=3;
    cout<<tilingproblem(2)<<endl;
    return 0;
}
