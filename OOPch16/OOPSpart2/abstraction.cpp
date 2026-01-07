#include<iostream>
using namespace std;

class shape{
    public:
   virtual void draw()=0;
};

class circle:public shape{
    public:
    void draw(){
        cout<<"drawing circle"<<endl;
    }
};

class rectangle:public shape{
    public:
    void draw(){
        cout<<"drawing rectangle"<<endl;
    }
};
int main(){
    circle cir1;
    cir1.draw();

    rectangle rec1;
    rec1.draw();
    return 0;
}