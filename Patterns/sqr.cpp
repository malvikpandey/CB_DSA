#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int i=1;
    int num=1;
    while(i<=n){
        for(int j=1; j<=n; j++){
            if(j < i){
                cout<<num<<' ';
            }else{
                cout<<num++<<" ";
            }
        }
        num=i+1;
        cout<<endl;
        i++;
    }
    return 0;
}