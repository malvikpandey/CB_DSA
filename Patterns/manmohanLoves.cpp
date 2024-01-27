#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        if(i%2==0){
            
            for(int j=1; j<=i; j++){
                if(j==1 || j==i){
                    cout<<'1';
                }else{
                    cout<<'0';
                }
                
            }
            cout<<endl;
            }else{
                for(int j=1; j<=i; j++){
                    cout<<"1";
                }
                cout<<endl;
            }
            i++;
        }
        return 0;
        
    }