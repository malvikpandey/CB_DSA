#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int i=1;
    int m = n - n/2;

    // 1st part
    while(i<=m){
        
        //initial spaces
        for(int j=1; j<= m-i; j++){
            cout<<" "<<'\t';
        }

        //stars
        for(int j=1; j<=2*i-1; j++){
            cout<<"*"<<'\t';
        }



        cout<<endl;
        i++;
    }
    i = 1;
    while(i < m){
        //spaces
        for(int j=1; j<=i; j++){
            cout<<" "<<'\t';
        }

        //stars
        for(int j=1; j<=n-2*i; j++){
            cout<<"*"<<'\t';
        }
        cout<<endl;
        i++;
    }

    return 0;
}
