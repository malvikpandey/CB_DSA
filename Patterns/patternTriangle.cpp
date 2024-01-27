#include<iostream>

using namespace std;

int main(){
    int i=1, n;
    cin>>n;
    
    while(i<=n){
        
        
        for(int j=1; j<=n-i; j++){
            cout<<' '<<'\t';
        }

        
        int num=i;
        for(int k=1; k<=i; k++){
            cout<<num<<'\t';
            num++;
        }

        num = 2*i-2;
        for(int l=1; l<=i-1; l++){
            cout<<num<<'\t';
            num--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}
