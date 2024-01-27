#include<iostream>
using namespace std;

int maxValue(int arr[], int n){
        int max = arr[0];
        for(int i=0; i<n; i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int max = maxValue(arr, n);

    cout<<max<<endl;
    return 0;
}