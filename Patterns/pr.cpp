#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    int num;
    int m = n + (n-1);
    while(i <= m){
        
        
        
        if(i <= n){
            num = i;
            for(int j=1; j<=n-i; j++){
                cout<<" "<<'\t';
            }

            for(int j=1; j<=i; j++){   
                cout<<num++<<'\t';
            }

            num -= 2;

            for(int j=1; j<=i-1; j++){   
                cout<<num--<<'\t';
            }
        }else{
            
            for(int j=1; j<=i-n; j++){
                cout<<" "<<'\t';
            }

             for(int j=1; j<=2*n-i; j++){   
                cout<<num++<<'\t';
            }

            num -= 2;

            for(int j=1; j<=2*n-i-1; j++){   
                cout<<num--<<'\t';
            }
        }
        cout<<endl;        
        i++;
    }
    return 0;
}