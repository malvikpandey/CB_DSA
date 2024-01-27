#include<iostream>

using namespace std;


int main(){
    int n;
    int m;
    cin>>n>>m;

    int arr[10][10] ={};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    bool res;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if(arr[i][j] != arr[i+1][j+1]){
                res = false;
            }else{
                res = true;
            }
        }
    }

    if(res){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}