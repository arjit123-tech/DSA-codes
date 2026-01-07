#include<iostream>
#include<vector>
using namespace std;
int lastoccurance(vector<int> arr, int key, int i){
    if(i==arr.size()){
        return -1;
    }
    int restarray=lastoccurance(arr,key,i+1);
    if(restarray!=-1){
        return restarray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}
int main(){
    vector<int> arr={1,2,3,3,3,4};
    cout<<lastoccurance(arr, 3, 0)<<endl;
    return 0;
}