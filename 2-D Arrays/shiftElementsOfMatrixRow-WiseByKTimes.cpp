#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int k;
    cin>>k;
   
    for(int i=0; i<n; i++){
        for(int j= n-1; j>=k; j--){
            swap(arr[i][j], arr[i][j-k]);
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}