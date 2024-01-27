#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i =1;
    while(i<=n){
        
        for(int j=1; j<= n-i; j++){
            cout<<" ";
        }
        if(i == 1 || i == n){
            for(int j=1; j <= n; j++){
                cout<<"*";
            }
        }else{
            for(int j=1; j <= 1; j++){
                cout<<"*";
            }

            for(int j=1; j <= n-2; j++){
                cout<<" ";
            }

            for(int j=1; j <= 1; j++){
                cout<<"*";
            }
        }
        cout<<endl;
        i++;
    }
    return 0;
}