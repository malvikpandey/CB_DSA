#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int i=1;
    int num=1;
    while(i<=n){
        for(int j=1; j<=(n-i+1); j++){
            cout<<num++<<" ";
        }
        num=1;
        for(int k=2; k<=i; k++){
            cout<<"*"<<" ";
        }
        for(int l=3; l<=i; l++){
            cout<<"*"<<" ";
        }
        cout<<endl;
        i++;
    }
    return 0;
}