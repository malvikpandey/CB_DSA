#include<iostream>
#include<algorithm>

using namespace std;

void sortArr(int* arr, int n){

    for(int i=0; i<n; i++){
        arr[i] = arr[i] * arr[i];
    }

    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n] = {};

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sortArr(arr, n);
    return 0;
}