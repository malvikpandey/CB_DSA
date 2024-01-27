#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;

    while(i<=n){

        //spaces
        for(int j=1; j<= i-1; j++){
            cout<<" ";
        }
        //stars
        for(int j=1; j<=n-i+1; j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
        i++;
    }
    return 0;
}