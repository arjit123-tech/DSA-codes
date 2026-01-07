#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void printlist(list<int> ll){
     list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){//this function is for print iterator
        cout<<*(itr)<<"->";
    }
    cout<<endl;
}

int main(){
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);
   printlist(ll);
   cout<<ll.size()<<endl;//for getting size of ll that is 4
    return 0;
}