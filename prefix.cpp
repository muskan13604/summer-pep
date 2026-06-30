#include<iostream>
using namespace std;


int main(){
    int a;
    cin>>a;
    int sum=0;
    int arr[a];
    for(int i=0; i<a; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<sum;

    

}