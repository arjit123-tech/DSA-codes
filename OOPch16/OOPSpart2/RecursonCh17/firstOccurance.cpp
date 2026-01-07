#include<iostream>
#include<vector>
using namespace std;
int firstOccurance(vector<int> arr, int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstOccurance(arr,n,i+1,key);
}
int main(){
    vector<int> arr={1,2,3,4,5,3,6};
    cout<<firstOccurance(arr, arr.size(), 0, 4)<<endl;
    return 0;
}