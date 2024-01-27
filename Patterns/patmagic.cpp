#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    int m = n + n/2 +2;
    int space = 1;

    while(i<= m){
        if(i == 1 || i == m){
            for(int j=1; j<=m; j++){
                cout<<"*";
            }
        }else if(i <= n){
            for(int j=1; j<=n-i+1; j++){
                cout<<"*";
            }
            //spaces
            for(int j=1; j<= space; j++){
                cout<<" ";
                
            }
            space +=2 ;

            for(int j=1; j<=n-i+1; j++){
                cout<<"*";
            }
        }else{
            if(space >= m){
                space -= 4;
            }

            for(int k=1; k<=i-n+1; k++){
                cout<<"*";
            }

            for(int k=1; k<= space; k++){
                cout<<" ";
            }
            space -= 2;
            
            for(int j=1; j<=i-n+1; j++){
                cout<<"*";
            }
        }
        cout<<endl;
        i++;
    }
    return 0;
}