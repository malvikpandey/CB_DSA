#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int m = n/2;

    //n stars in 1st row
    for(int i=1; i<=n;i++){
            cout<<'*'<<'\t';
    }
    cout<<endl;

    //stars and spaces
    for(int i=1; i<= m; i++){
        //stars
        for (int j=1; j <= m-i+1; j++)
        {
            cout<<'*'<<'\t';
        }

        //spaces
        for(int j=1; j<= 2*i-1; j++){
            cout<<" "<<'\t';
        }

        //stars
        for (int j=1; j <= m-i+1; j++)
        {
            cout<<'*'<<'\t';
        }

        cout<<endl;
    }
    //3rd stars and spaces
    for(int i=1 ; i<=m-1; i++){
        //stars
        for (int j=1; j <= i+1; j++)
        {
            cout<<'*'<<'\t';
        }

        //spaces
        for(int j=1; j<=2*(m-i)-1; j++){
            cout<<" "<<'\t';
        }

        //stars
        for (int j=1; j <= i+1; j++)
        {
            cout<<'*'<<'\t';
        }

        cout<<endl;
    }
    //n stars in last row
    for(int i=1; i<=n;i++){
        cout<<'*'<<'\t';
    }
    return 0;
}