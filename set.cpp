#include<iostream>
#include<set>

using namespace std;

int main() {
    set<int> s;
    s.insert(20);
    s.insert(10);
    s.insert(20);
    cout<<s.size()<<endl;
    s.erase(10);
    cout<<s.size()<<endl;
    s.clear();
    cout<<s.size()<<endl;
    if(s.find(20)==s.end(){
        return"false";
    }
    else{
        return "true";
    })
    s.insert(30);
    if(s.find(30)==s.end(){
        return"false";
    }
    else{
        return "true";
    })
    cout<<s.size();
}