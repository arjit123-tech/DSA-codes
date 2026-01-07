#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool campare(pair<double,int> a, pair<double,int> b){
    return a.first>b.first;
}
int fractionalknapsack(vector<int> val, vector<int> weight, int w){
    int n=val.size();
    vector<pair<double,int>> ratio(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        double r=val[i]/weight[i];
        ratio[i]=make_pair(r,i);
    }
    sort(ratio.begin(), ratio.end(), campare);
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=ratio[i].second;
        if(weight[idx]<=w){
            ans+=val[idx];
            w-=weight[idx];
        }
        else{
            ans+=ratio[i].first*w;
            break;
        }
    }
    cout<<"max value= "<<ans<<endl;
    return ans;
}
int main(){
vector<int> val={60,100,120};
vector<int> weight={10,20,30};
int w=50;//capacity 
fractionalknapsack(val, weight, w);
    return 0;
}