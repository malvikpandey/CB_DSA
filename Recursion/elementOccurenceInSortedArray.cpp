#include<iostream>

using namespace std;

int count = 0;
int eleOcurr(int *arr, int n, int target, int i){
    //base case
    if(i == n){
        return -1;
    }

    //recursive case
    if(arr[i] == target){
        count++;
    }

    eleOcurr(arr, n, target, i+1);

    if(count>0){
        return count;
    }

    return -1;
}

int main(){
    int arr[100000];
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int target;
    cin>>target;

    cout<< eleOcurr(arr, n, target, 0);
    return 0;
}