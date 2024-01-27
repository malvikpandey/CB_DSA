#include<iostream>
using namespace std;

int main(){
    int n, sum, a=0, b=1;
    cin>>n;

    for(int i=1; i<=n; i++){

        for(int j=1; j<=i; j++){
            if(i == 1){
                cout<<a<<'\t';
                // num++;
                // sum = sum + num;
            }else if(i == 2){
                cout<<b<<'\t';
                sum = a+b;
                a=b;
                // sum = sum + num;
            }else{
                cout<<sum<<'\t';
                // sum = sum - num;
                a=b;
                b=sum;
                sum = a+b;
            }
        }
        
        
        cout<<endl;
        
    }
    return 0;
}