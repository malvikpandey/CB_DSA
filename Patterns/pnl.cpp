#include<iostream>
using namespace std;

int main(){
    int i=1, n, num=1;
    cin>>n;
    while(i<=n){
        

        for(int j=1; j<=i; j++){
            cout<<num<<'\t';
            num++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}