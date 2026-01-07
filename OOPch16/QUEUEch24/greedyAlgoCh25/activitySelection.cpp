#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxactivity(vector<int> start, vector<int> end){
   int count=1;
   int currend=end[0];
   for( int i=1;i<end.size();i++){
       if(start[i]>=currend){
           count++;
           currend=end[i];
       }
   }
   return count; 
}
bool comp (int a, int b){
  return a<b;
}
bool compare (pair<int , int> p1, pair<int, int> p2){
  return p1.second < p2.second; // sorting on the basis of second membe
}
int main(){
    // vector<int> start={1,3,0,5,8,5};
    // vector<int> finish={2,4,6,7,9,9};

  // cout<<maxactivity(start,finish)<<endl;
// from here start pairing in c++
  vector<int> start={0,1,2};
    vector<int> finish={9,2,4};
    vector<pair<int,int>> activities(3, make_pair(0,0));
    activities[0]=make_pair(0,9);
    activities[1]=make_pair(1,2);
    activities[2]=make_pair(2,4);
    for(int i=0;i<activities.size();i++){
    cout<<activities[i].first<<", "<<activities[i].second<<endl;
    }
    sort(activities.begin(), activities.end(), compare);
    cout<<"after sorting "<<endl;
    for(int i=0;i<activities.size();i++){
    cout<<activities[i].first<<", "<<activities[i].second<<endl;
    }
    return 0;
}