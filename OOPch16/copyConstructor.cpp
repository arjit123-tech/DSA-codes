#include<iostream>
#include<string>
using namespace std;
class car{
    public:
    string name;
    string color;
    car(string n, string c) {
        name = n;
        color = c;
    }
};
int main(){
    car c1("scorpio","Black");
    car c2(c1);
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    return 0;
}