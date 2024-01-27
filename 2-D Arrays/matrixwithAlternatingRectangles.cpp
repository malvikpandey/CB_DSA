#include<iostream>
#include<cstring>

using namespace std;


int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    int arr[n][m];

    int sr=0;
    int sc=0;
    int er=n-1;
    int ec=m-1;
    bool printX = true;

    while(sr<=er && sc<=ec){
        if(printX){
            for(int i=sr; i<=er;i++){
                arr[i][sc] = 'X';
            }
        }else{
            for(int i=sr; i<=er;i++){
                arr[i][sc] = 48;
            }
        }

        sc++;

        if(printX){
            for(int i=sc; i<=ec; i++){
                arr[er][i]='X';
            }
        }else{
            for(int i=sc; i<=ec; i++){
                arr[er][i] = 48;
            }
        }

        er--;

        if(printX){
            for(int i=er; i>=sr; i--){
                arr[i][ec] = 'X';
            }
        }else{
            for(int i=er; i>=sr; i--){
                arr[i][ec] = 48;
            }
        }

        ec--;

        if(printX){
            for(int i=ec; i>=sc; i--){
                arr[sr][i] = 'X';
            }
        }else{
            for(int i=ec; i>=sc; i--){
                arr[sr][i] = 48;
            }
        }

        sr++;

        printX = !printX;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<< char(arr[i][j])<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}