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

    int sr=0;
    int sc=0;
    int er=n-1;
    int ec=m-1;

    while(sr<=er && sc<=ec){

        for(int i=sr; i<=er;i++){
            cout<<arr[i][sc]<<", ";
        }

        sc++;

        for(int i=sc; i<=ec; i++){
            cout<<arr[er][i]<<", ";
        }

        er--;

        for(int i=er; i>=sr; i--){
            cout<<arr[i][ec]<<", ";
        }

        ec--;

        for(int i=ec; i>=sc; i--){
            cout<<arr[sr][i]<<", ";
        }

        sr++;
    }
    cout<<"END";
    return 0;
}