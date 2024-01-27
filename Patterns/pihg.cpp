#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    int start = n;
    
    while(i <= 2*n+1){
        int num = n;
        

        if(i <= n+1){
        //initial numbers

            for(int j=1; j<=i ;j++){
                cout<<num--<<" ";
            }
        
        //spaces
            for(int j=1; j<=(n-i)*2+1; j++){
                cout<<"  ";
            }
        num++;

        // numbers in dec. order
            for(int j=1; j<=i ;j++){
                if(num > 0){
                    cout<<num++<<" ";
                }else{
                    num++;
                }
            }
        }else{
            //numbers
            for(int j=start; j>0; j--){
                cout<<num--<<" ";
            }
            //spaces
            for(int j=1; j<= 2*(i-n)-3; j++){
                cout<<"  ";
            }
            //numbers
            for(int j=start; j>0; j--){
                cout<<++num<<" ";
            }
            start--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}