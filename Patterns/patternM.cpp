#include<iostream>

using namespace std;

int main(){
    int num = 1, n;
    cin>>n;

    for(int i=1; i<=n; i++){


        for(int j=1; j<=i; j++){
            cout<<num++<<'\t';

        }
        for(int k=1; k<=2*(n-i)-1; k++){
            cout<<' '<<'\t';
        }
        for(int l=1; l<=i; l++){
            num--;
            if(l == n){
                break;
            }else if(i == n){
                num--;
                cout<<num++<<"\t";
            }else{    
                cout<<num<<'\t';
            }
            
        }
        num=1;
        cout<<endl;
    }
    return 0;
}