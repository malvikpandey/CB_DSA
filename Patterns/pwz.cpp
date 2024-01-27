#include<iostream>
using namespace std;

int main(){
    int num=1, n;
    cin>>n;

    for(int i=1; i<=n;i++){

        for(int j=1; j<=i; j++){
            if( j!=1 && j!=i && num>=3 ){
                cout<<'0'<<'\t';
            }else{
                cout<<num<<'\t';
            }
        }
        num++;
        cout<<endl;
    }
    return 0;
}