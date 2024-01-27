#include<iostream>  
using namespace std;

int srcEle(int arr[], int n, int sr){
        int idx;
        bool flag;
        for(int i=0; i<n; i++){
            if(sr == arr[i]){
                idx = i;
                flag = true;
                break;
            }
        }
        
        if(!flag){
            idx = -1;
        }
    return idx;    
}

int main(){
    int n;
    cin>>n;
    int arr[n] = {};

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int sr;
    cin>>sr;

    int index = srcEle(arr, n, sr);

    cout<<index;
    return 0;
}