#include<iostream>
#include<cmath>
using namespace std;

void isArmstrong(int n){
       int len = 0;
       int tmp = n;
       int armst = 0;
       while(tmp > 0){
            tmp = tmp/10;
            len++;
       }

       tmp = n;

       while(n > 0){
            armst += pow(n%10, len);
            n=n/10;
       }

       if(tmp == armst){
            cout<<"true";
       }else{
            cout<<"false";
       }
}

int main(){
    int n;
    cin>>n;
    isArmstrong(n);
    return 0;
}