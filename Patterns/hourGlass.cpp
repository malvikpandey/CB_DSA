#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    int num = n;
    while (i <= (2*n)+1)
    {
        if (i <= n+1)
        {

            //spaces
            for(int j=1 ; j<=i-1 ;j++){
                cout<<"  ";
            }


            for(int j=1; j <= n-i+2; j++){
                    cout<<num--<<" ";
                
            }

            
            for(int j=1; j <= n-i+2; j++){
                if(num <= 0){
                    num += 2;
                }else{
                    cout<<num++<<" ";
                    }
            }
            num -= 2;
        }else{
            if(num < 0){
                num += 2;
            }

            //spaces
            for(int j=1; j<= 2*n-i+1; j++){
                cout<<"  ";
            }

            for(int j=1; j<= i-n; j++){
                cout<<num--<<" ";
            }

            for(int j=1; j<= i-n; j++){
                if(num < 0){
                    num += 2;
                }else{
                    cout<<num++<<" ";
                }
            }

        }
        
        cout<<endl;
        i++;
    }
    
    return 0;
}