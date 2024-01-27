#include<iostream>

using namespace std;


int main(){
    int n;
    int m;

    cin>>n>>m;

    int arr[n][m];

    for(int k=0; k<n; k++){
        for(int l=0; l<m; l++){
                cin>>arr[k][l];
        }
    }

    bool up = true;

    int row = 0;
    int col = 0;

    while(row<n && col<m){
        if(up){
            while(row>0 && col<m-1){
                cout<<arr[row][col]<<" ";
                row--;
                col++;
            }
            cout<<arr[row][col]<<" ";

            if(col == m-1){
                row++;
            }else{
                col++;
            }

        }else{
            while(col>0 && row<n-1){
                cout<<arr[row][col]<<" ";
                row++;
                col--;
            }
            cout<<arr[row][col]<<" ";

            if(row == n-1){
                col++;
            }else{
                row++;
            }
        }

        up = !up;
    }
    return 0;
}