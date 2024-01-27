#include<iostream>  
using namespace std;

int lc(int num1, int num2){

    for(int n=1; n<= num1*num2; n++){
        if(n%num1 == 0 && n%num2 == 0){
            return n;
        }else{
            return 0;
        }
    }
 
}

int main(){
    int num1;
    cin>>num1;
    int num2;
    cin>>num2;

    int Lcm = lc(num1, num2);
    cout<<Lcm<<endl;

    return 0;
}