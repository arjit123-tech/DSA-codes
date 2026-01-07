// #include<iostream>
// using namespace std;
// void counter(){
//     static int count=0;
//     count++; 
//     cout<<"count:"<<count<<endl;
// }
// int main(){
//     counter();
//     counter();
//     counter();
//     counter();

//     return 0;
// }
#include<iostream>
using namespace std;
class example{
    public:
    static int x;
};
int example::x=0;
int main(){
    example eg1;
    example eg2;
    example eg3;

    cout<<eg1.x++<<endl;
    
    cout<<eg2.x++<<endl;
    cout<<eg3.x++<<endl;
    return 0;
}