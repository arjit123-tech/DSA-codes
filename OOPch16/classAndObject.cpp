#include<iostream>
using namespace std;
class Student{//this is properties
    string name;
    float cgpa;
    void getpercentage(){//this is methods
        cout<<"Percentage: "<<cgpa*10<<endl;
    }
};
int main(){
    Student s1;//is s1 mai student ki sari details store hongi
    
    return 0;
} 