#include<iostream>
using namespace std;

int lc(int num1, int num2){
    int fac = 0;
    for(int n=1; n<= num1*num2/2 ; n++){
        if(n%num1 == 0 && n%num2 == 0){
            fac = n;
        }else{
            continue;
        }
    }
    return fac;
}

int gcd(int a, int b){
        int l = lc(a,b);
        
        return a*b/l;
}

int main(){
    int a;
    int b;
    cin>>a>>b;
    int gc = gcd(a, b);

    cout<<gc;
    return 0;
}