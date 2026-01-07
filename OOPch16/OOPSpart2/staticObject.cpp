#include<iostream>
using namespace std;
class example{
    public:
    example(){
        cout<<"constructor called"<<endl;
    }
    ~example(){
        cout<<"destructor..."<<endl;
    }
};
int main(){
    int a=0;

if(a==0){
    example eg1;
}
cout<<"code ending"<<endl;
   return 0;
}