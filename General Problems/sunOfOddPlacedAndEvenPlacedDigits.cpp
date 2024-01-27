#include<iostream>
using namespace std;

void sumOfOddandEven(int n){
    int count = 1;
    int sumOfEven = 0;
    int sumOfOdd = 0;

    while(n > 0){
        if(count%2 == 0){
            sumOfEven += n % 10;
            count++;
        }else{
            sumOfOdd += n % 10;
            count++;
        }
        n = n / 10;
    }
    cout<<sumOfOdd<<endl;
    cout<<sumOfEven<<endl;
}

int main(){
    int n;
    cin >> n;

    sumOfOddandEven(n);

    return 0;
}