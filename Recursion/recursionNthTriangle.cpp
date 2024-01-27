#include<iostream>

using namespace std;


int sum = 0;

int rTriangle(int n, int i){
    //base case
    if(i == n+1){
        return 0;
    }

    //recursive case
    if(i<=n){
        sum = i+rTriangle(n, i+1);;    
    }

       
    return sum;
}

int main(){
    int n;
    cin>>n;
    
    cout<<rTriangle(n, 1)<<endl;

    return 0;
}