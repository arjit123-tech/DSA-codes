#include<iostream>
#include<string>
using namespace std;
void removeduplicate(string str, string ans, int i, int map[26]){
    if(i==str.length()){
        cout<<ans<<endl;
        return;
    }
    
    char ch=str[i];
    int mapidx=(int)(ch-'a');
    if(map[mapidx]==true){//duplicate
        removeduplicate(str, ans, i+1, map);
    }else{//not duplicate 
        map[mapidx]=true;
        removeduplicate(str, ans+str[i], i+1, map);
    }
}
int main(){
     string str="appnnacollege";
    string ans="";
    int map[26] = {0};
    removeduplicate(str, ans, 0, map);
    return 0;
}