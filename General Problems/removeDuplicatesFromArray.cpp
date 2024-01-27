#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    int rdArr[n];
    int count = 0;
    

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    rdArr[0] = arr[0];

    for(int i=0; i<n; i++){
        if(arr[i] == arr[i+1]){
            continue;
        }else{
            count++;
            rdArr[count] = arr[i+1];
        }
    }


    cout<<count<<endl;
    for(int i=0; i<count; i++){
        cout<<rdArr[i];
    }
}