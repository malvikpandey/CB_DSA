#include<iostream>
#include<algorithm>

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

    int res[n][n] = {};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            res[i][j] = arr[j][n-i-1];

        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;

    }    
    return 0;
}