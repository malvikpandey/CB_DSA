#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        if(i<=n/2+1){
            if(i == 1){
                cout<<"*";

                for(int j=1; j<=(n/2+1)-2; j++){
                    cout<<" ";
                }

                for(int j=1; j<= n/2+1; j++){
                    cout<<"*";
             }
            }else if(i == n/2+1){
                for(int j=1; j<=n; j++){
                    cout<<"*";
                }
            }else{
                for(int j=1; j<=n/2+1; j++){
                    if(j==1 || j==(n/2)+1){
                        cout<<"*";
                    }else{
                        cout<<" ";
                    }
                }
            }
        }else{
            if(i == n){
                for(int j=1; j<= n/2+1; j++){
                    cout<<"*";
                }

                for(int j=1; j<=(n/2+1)-2; j++){
                    cout<<" ";
                }

                cout<<"*";
                
            }else{
                for(int j=1; j<=n; j++){
                   if(j==n || j==(n/2+1)){
                        cout<<"*";
                    }else{
                        cout<<" ";
                    }
                }

            }
        
        }
        cout<<endl;
        i++;
    }
    return 0;
}