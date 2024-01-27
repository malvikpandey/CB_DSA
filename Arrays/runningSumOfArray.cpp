#include<iostream>

using namespace std;

void rSOA(int *arr, int n){
    int sum=0;

    for(int i=0; i<n; i++){
        sum += arr[i];
        cout<<sum<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    rSOA(arr, n);

    return 0;
}