#include<iostream>
#include<algorithm>

using namespace std;

void bubbleSortRecursive(int* arr, int n, int i) {
    //base case
    if(i == n || n == 1){
        return;
    }

    //recursive case
    int j=0;
    while(j < n-i) {
        if(arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
        j++;
    }
    bubbleSortRecursive(arr, n, i+1);

}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubbleSortRecursive(arr, n, 1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}