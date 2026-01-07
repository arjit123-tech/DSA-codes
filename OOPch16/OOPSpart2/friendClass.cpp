#include<iostream>
#include<string>
using namespace std;
class A{
    string secret="secret data";
    friend class B;
};
class B{
    public:
    void showSecret(A &obj){
        cout<<obj.secret<<endl;
    }
};
int main(){
A a1;
B b1;
b1.showSecret(a1);
    return 0;
}