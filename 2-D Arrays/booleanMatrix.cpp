#include<iostream>
#include<cstring>

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

    int row[n] = {};
    int col[m] = {};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] == 1 || col[j] == 1){
                arr[i][j] = 1;
            }
        }
    }
    

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}