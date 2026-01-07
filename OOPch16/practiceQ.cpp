#include<iostream>
#include<string>
using namespace std;
class user{
private:
    int id;
    string password;
public:
string username;
user(int id){
    this->id=id;
    }
    //getter
    string getpassword(){
        return password;
    }
    //setter
    void setpassword(string password){
        this->password=password;
    }
};
int main(){
    user user1(101);
    user1.username="arjitsharma";
    user1.setpassword("arjit@123");
    cout<<"username: "<<user1.username<<endl;
    cout<<"password: "<<user1.getpassword()<<endl;
    return 0;
}