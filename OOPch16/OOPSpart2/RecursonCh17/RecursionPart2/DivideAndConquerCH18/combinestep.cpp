#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei){
    vector<int>temp;
    int i=si;//left part starting index
    int j=mid+1;//right part starting index
    while(i<=mid&& j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    //copy temp to original array
    int x = 0;
    for(int idx=si; idx<=ei; idx++){
        arr[idx]=temp[x++];
    }
}
void mergesort(int arr[], int si, int ei){
    if (si>=ei)
    {
        return ;/* code */
    }
    
    int mid=si+(ei-si)/2;
    mergesort(arr,si,mid);//left half
    mergesort(arr,mid+1,ei);//right half
    merge(arr,si,mid,ei);
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[6]={6,3,7,5,2,4};
    int n=6;
    mergesort(arr,0,n-1);
    printarr(arr,n);
    return 0;
}