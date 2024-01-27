#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int maxH = 0;

    for(int i=1; i+1<n; i++){
        int sum = 0;
        for(int j=1; j+1<m; j++){
            sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i][j] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
            maxH = max(maxH, sum);
        }
        
    }

    

    cout<<maxH<<endl;
    return 0;
}