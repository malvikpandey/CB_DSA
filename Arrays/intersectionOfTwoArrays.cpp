#include<iostream>
#include<algorithm>

using namespace std;

void iota(int* arr, int* brr, int n){

    sort(arr, arr+n);
    sort(brr, brr+n);

    int ans[n]={};
    int visit[n]={};
    int k=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i] == brr[j] && visit[j] == 0){
                ans[k] = arr[i];
                k++;
                visit[j] = 1;
                break;
            }

            if(arr[i]<brr[j]){
                break;
            }
        }
    }

    cout<<"[";
    for(int i=0; i<n; i++){
        if(ans[i] != 0){
            cout<<ans[i];
        }

        if(i != n-1 && ans[i+1] != 0){
            cout<<", ";
        }
    }
    cout<<"]";
}

int main(){
    int n;
    cin>>n;
    int arr[n], brr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        cin>>brr[i];
    }

    iota(arr, brr, n);

    return 0;
}